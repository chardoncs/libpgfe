#include "utils.h"

#include "generic-internal.h"

size_t pgfe_hash_to_hex_string(const pgfe_encode_t hash[], size_t hash_length, char out[]) {
    char *op = out, dual_hex[3];

    for (size_t i = 0; i < hash_length; i++) {
        sprintf(dual_hex, "%02x", hash[i]);
        *(op++) = dual_hex[0];
        *(op++) = dual_hex[1];
    }

    *op = 0;

    return op - out;
}

size_t pgfe_hex_string_to_hash(const char hash_s[], pgfe_encode_t hash_out[]) {
    short pos;
    size_t hash_str_len = strlen(hash_s);
    pgfe_encode_t hexu = 0, tmp_o, *op;
    char *sp = (char *)hash_s, tpc;

    tpc = hash_s[1];
    if (hash_str_len >= 2 && (tpc == 'x' || tpc == 'X')) {
        sp += 2;
        hash_str_len -= 2;
    }

    tpc = sp[hash_str_len - 1];
    if (tpc == 'h' || tpc == 'H') {
        hash_str_len--;
    }

    for (op = hash_out, pos = hash_str_len % 2; *sp; sp++) {
        __pgfe_ch2hex(*sp, &tmp_o);

        if (tmp_o == PGFE_HEX_UNKNOWN_CHAR) {
            continue;
        }

        hexu |= tmp_o;
        if (!pos) {
            hexu <<= 4;
        }
        else {
            *(op++) = hexu;
            hexu = 0;
        }

        pos ^= 1;
    }

    return op - hash_out;
}

void pgfe_print_hash(const pgfe_encode_t hash[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", hash[i]);
    }
}

size_t pgfe_hash_string_clean(const char hash_s[], char output[]) {
    pgfe_encode_t h;
    char *sp = (char *)hash_s, *op = output;
    int offset_flag = -1;

    for (; *sp; sp++) {
        if (offset_flag < 2) {
            if (++offset_flag == 1 && (*sp == 'x' || *sp == 'X')) {
                op = output;
                continue;
            }
        }

        __pgfe_ch2hex(*sp, &h);
        if (h == PGFE_HEX_UNKNOWN_CHAR) {
            continue;
        }

        *(op++) = *sp;
    }

    *op = 0;
    return op - output;
}

inline size_t pgfe_hash_string_clean_(char hash_s[]) {
    return pgfe_hash_string_clean(hash_s, hash_s);
}

size_t pgfe_hash_length(const char hash_s[]) {
    size_t len = strlen(hash_s);
    char s[len + 1];

    pgfe_hash_string_clean(hash_s, s);
    len = strlen(s);

    return len / 2 + len % 2;
}

inline time_t pgfe_curtime() {
    return time(NULL);
}