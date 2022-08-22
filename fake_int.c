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
    int count32 = 32 - count;

    fnum.high = (fnum.high << count) | (count32 >= 0 ? (fnum.low >> count32) : (fnum.low << -count32));
    fnum.low <<= count;
    return fnum;
}

pf_uint64_t pf64_rshift(pf_uint64_t fnum, int count) {
    int count32 = 32 - count;

    fnum.low = (fnum.low >> count) | (count32 >= 0 ? (fnum.low << count32) : (fnum.low >> -count32));
    fnum.high >>= count;
    return fnum;
}

pf_uint64_t pf64_clshift(pf_uint64_t fnum, int count) {
    return pf64_OR(pf64_lshift(fnum, count), pf64_rshift(fnum, 64 - count));
}

pf_uint64_t pf64_crshift(pf_uint64_t fnum, int count) {
    return pf64_OR(pf64_rshift(fnum, count), pf64_lshift(fnum, 64 - count));
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