#include "fake_int.h"

#ifdef __PGFE_ARCH_COMPAT

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

pf_uint64_t to_pf64(uint32_t num) {
    pf_uint64_t n;
    n.l = 0;
    n.r = num;
    return n;
}

pf_uint64_t to_pf64_2(uint32_t left, uint32_t right) {
    pf_uint64_t n;
    n.l = left;
    n.r = right;
    return n;
}

#else

#include "generic-internal.h"

#define pf64_add(l, r) ((l) + (r))

#define pf64_sub(l, r) ((l) - (r))

#define pf64_AND(l, r) ((l) & (r))

#define pf64_OR(l, r) ((l) | (r))

#define pf64_XOR(l, r) ((l) ^ (r))

#define pf64_NOT(n) (~(n))

#define pf64_lshift(n, c) ((n) << (c))

#define pf64_rshift(n, c) ((n) >> (c))

#define pf64_clshift(n, c) clshift(n, c)

#define pf64_crshift(n, c) crshift(n, c)

#define to_pf64(n) ((uint64_t)(n))

#define to_pf64_2(l, r) (((uint64_t)(r)) | ((uint64_t)(l) << 32));

#endif