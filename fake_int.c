#include "fake_int.h"

pf_uint64_t pf64_add(pf_uint64_t left, pf_uint64_t right) {
    left.r += right.r;
    left.l = left.l + right.l + (left.r < right.r);
    return left;
}

pf_uint64_t pf64_sub(pf_uint64_t left, pf_uint64_t right) {
    left.r -= right.r;
    left.l = left.l - right.l - (left.r > right.r);
    return left;
}

pf_uint64_t pf64_AND(pf_uint64_t left, pf_uint64_t right) {
    left.l &= right.l;
    left.r &= right.r;
    return left;
}

pf_uint64_t pf64_OR(pf_uint64_t left, pf_uint64_t right) {
    left.l |= right.l;
    left.r |= right.r;
    return left;
}

pf_uint64_t pf64_XOR(pf_uint64_t left, pf_uint64_t right) {
    left.l ^= right.l;
    left.r ^= right.r;
    return left;
}

pf_uint64_t pf64_NOT(pf_uint64_t fnum) {
    fnum.l ^= 0xFFFFFFFF;
    fnum.r ^= 0xFFFFFFFF;
    return fnum;
}

pf_uint64_t pf64_lshift(pf_uint64_t fnum, int count) {
    int count32 = 32 - count;

    fnum.l = (fnum.l << count) | (count32 >= 0 ? (fnum.r >> count32) : (fnum.r << -count32));
    fnum.r <<= count;
    return fnum;
}

pf_uint64_t pf64_rshift(pf_uint64_t fnum, int count) {
    int count32 = 32 - count;

    fnum.r = (fnum.r >> count) | (count32 >= 0 ? (fnum.r << count32) : (fnum.r >> -count32));
    fnum.l >>= count;
    return fnum;
}

pf_uint64_t pf64_clshift(pf_uint64_t fnum, int count) {
    return pf64_OR(pf64_lshift(fnum, count), pf64_rshift(fnum, 64 - count));
}

pf_uint64_t pf64_crshift(pf_uint64_t fnum, int count) {
    return pf64_OR(pf64_rshift(fnum, count), pf64_lshift(fnum, 64 - count));
}