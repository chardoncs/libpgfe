#include "fake_int.h"

#ifdef __PGFE_ARCH_COMPAT

pf_uint64_t pf64_add(pf_uint64_t left, pf_uint64_t right) {
    left.low += right.low;
    left.high = left.high + right.high + (left.low < right.low);
    return left;
}

pf_uint64_t pf64_sub(pf_uint64_t left, pf_uint64_t right) {
    left.low -= right.low;
    left.high = left.high - right.high - (left.low > right.low);
    return left;
}

pf_uint64_t pf64_AND(pf_uint64_t left, pf_uint64_t right) {
    left.high &= right.high;
    left.low &= right.low;
    return left;
}

pf_uint64_t pf64_OR(pf_uint64_t left, pf_uint64_t right) {
    left.high |= right.high;
    left.low |= right.low;
    return left;
}

pf_uint64_t pf64_XOR(pf_uint64_t left, pf_uint64_t right) {
    left.high ^= right.high;
    left.low ^= right.low;
    return left;
}

pf_uint64_t pf64_NOT(pf_uint64_t fnum) {
    fnum.high ^= 0xFFFFFFFF;
    fnum.low ^= 0xFFFFFFFF;
    return fnum;
}

pf_uint64_t pf64_lshift(pf_uint64_t fnum, int count) {
    if (!count) return fnum;

    int count32 = 32 - count;

    if (count < 32) {
        fnum.high = (fnum.high << count) | (fnum.low >> count32);
        fnum.low <<= count;
    }
    else {
        fnum.high = fnum.low << -count32;
        fnum.low = 0;
    }

    return fnum;
}

pf_uint64_t pf64_rshift(pf_uint64_t fnum, int count) {
    if (!count) return fnum;

    int count32 = 32 - count;

    if (count < 32) {
        fnum.low = (fnum.low >> count) | (fnum.low << count32);
        fnum.high >>= count;
    }
    else {
        fnum.low = fnum.high >> -count32;
        fnum.high = 0;
    }

    return fnum;
}

pf_uint64_t pf64_clshift(pf_uint64_t fnum, int count) {
    return pf64_OR(pf64_lshift(fnum, count), pf64_rshift(fnum, 64 - count));
}

pf_uint64_t pf64_crshift(pf_uint64_t fnum, int count) {
    return pf64_OR(pf64_rshift(fnum, count), pf64_lshift(fnum, 64 - count));
}

inline uint32_t pf64_r(pf_uint64_t fnum) {
    return fnum.low;
}

inline uint32_t pf64_l(pf_uint64_t fnum) {
    return fnum.high;
}

pf_uint64_t to_pf64(uint32_t num) {
    pf_uint64_t n;
    n.high = 0;
    n.low = num;
    return n;
}

pf_uint64_t to_pf64_2(uint32_t high, uint32_t low) {
    pf_uint64_t n;
    n.high = high;
    n.low = low;
    return n;
}

#endif