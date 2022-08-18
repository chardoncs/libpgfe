#include "base-encoding-internal.h"

#include "generic-internal.h"

inline pgfe_mask_t __pgfe_build_mask(uint8_t digit_c) {
    return ((pgfe_mask_t)-1) >> (sizeof(pgfe_mask_t) * 8 - digit_c);
}

size_t __pgfe_transform_codes(const pgfe_encode_t input[], size_t length, uint8_t chunk_size, pgfe_encode_t out[]) {
    const uint16_t bitsz = sizeof(pgfe_encode_t) * 8;
    pgfe_encode_t *inp = (pgfe_encode_t *)input, *op = out;
    size_t low, high, mv_sz, sz_diff;

    const pgfe_mask_t chunk_mask = __pgfe_build_mask(chunk_size);

    for (low = 0, high = chunk_size % bitsz; inp - input <= length; inp++, op++) {
        if (low < high) {
            *op = ((*inp) >> (bitsz - high)) & chunk_mask;
            inp--;
        }
        else if (!high) {
            *op = (*inp) & chunk_mask;
        }
        else {
            sz_diff = bitsz - low;
            mv_sz = chunk_size - sz_diff;
            *op = ((*inp) & __pgfe_build_mask(sz_diff)) << mv_sz;
            if (inp - input + 1 < length) {
                *op |= ((*(inp + 1)) >> (bitsz - high)) & __pgfe_build_mask(high);
            }
        }

        low = (low + chunk_size) % bitsz;
        high = (high + chunk_size) % bitsz;
    }

    return op - out;
}

size_t __pgfe_unittostr(
    size_t chunk_count, size_t unit_size, size_t bit_size, size_t alphabet_size, const char alphabet[],
    const pgfe_encode_t unit[], char out[], bool padding
) {
    char unit_s[chunk_count];
    pgfe_encode_t unit_split[chunk_count];
    int i;

    __pgfe_transform_codes(unit, unit_size, bit_size, unit_split);
    for (i = 0; i < chunk_count; i++) {
        unit_s[i] = alphabet[unit_split[i]];
    }

    if (padding) {
        for (i = chunk_count - 1; i >= 0; i--) {
            if (unit_s[i] != alphabet[0]) {
                break;
            }

            unit_s[i] = alphabet[alphabet_size];
        }
    }

    memcpy(out, unit_s, chunk_count);
    return chunk_count;
}

size_t __pgfe_encode_generic(
    PGFE_BASE_PARAMS_DEF, const char alphabet[], const pgfe_encode_t input[], size_t input_length, char cs_out[]
) {
    pgfe_encode_t input_unit[unit_size], *inp = (pgfe_encode_t *)input;
    size_t i, remain;
    char *sp = cs_out;

    for (i = 0; i < input_length; i += unit_size) {
        remain = input_length - i;
        if (remain < unit_size) {
            __pgfe_arrinit(input_unit, unit_size);
            memcpy(input_unit, inp, remain);
        }
        else {
            memcpy(input_unit, inp, unit_size);
            remain = unit_size;
        }

        sp += __pgfe_unittostr(
            chunk_count, unit_size, bit_size, alphabet_size, alphabet, input_unit, sp, unit_size - remain
        );
        inp += unit_size;
    }

    *sp = 0;
    return sp - cs_out;
}

size_t __pgfe_decode_generic(
    PGFE_BASE_PARAMS_DEF, pgfe_encode_t (*func)(char), const char basexx_cs[], pgfe_encode_t output[]
) {
    pgfe_encode_t *op, ch, sig, o_unit[unit_size];
    const size_t sz_ou = sizeof(pgfe_encode_t) * 8;
    char *sp = (char *)basexx_cs;
    size_t i = 0, j;
    uint64_t u;
    const pgfe_mask_t mask = __pgfe_build_mask(bit_size);

    op = output;
    while (*sp) {
        for (i = 0, u = 0; *sp && i < chunk_count; sp++) {
            ch = func(*sp);
            sig = ch & 0xC0;

            if (sig == PGFE_BASE_UNKNOWN_CODE) {
                continue;
            }

            u <<= bit_size;
            u |= ch & mask;

            i++;
        }

        if (!*sp && i < chunk_count) {
            u <<= bit_size * (chunk_count - i);
        }

        for (j = 0; j < unit_size; j++) {
            o_unit[j] = (pgfe_encode_t)((u >> (sz_ou * (unit_size - j - 1))) & 0xFF);
        }

        memcpy(op, o_unit, unit_size);
        op += unit_size;
    }

    // Determine end of the output
    op -= unit_size;
    for (i = 0; i < unit_size && op[i] == o_unit[i] && op[i]; i++)
        ;

    op += i;
    *op = 0;
    return op - output;
}