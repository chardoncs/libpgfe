#ifndef LIBPGFE_FAKE_INT_H
#define LIBPGFE_FAKE_INT_H

#include <stdint.h>

#include "architecture.h"

#ifdef __cplusplus
extern "C" {
#endif
#define __PGFE_ARCH_COMPAT
#ifdef __PGFE_ARCH_COMPAT

typedef struct pgfe_fake_uint64
{
    uint32_t low, high;
} pf_uint64_t;

pf_uint64_t pf64_add(pf_uint64_t left, pf_uint64_t right);

pf_uint64_t pf64_sub(pf_uint64_t left, pf_uint64_t right);

pf_uint64_t pf64_AND(pf_uint64_t left, pf_uint64_t right);

pf_uint64_t pf64_OR(pf_uint64_t left, pf_uint64_t right);

pf_uint64_t pf64_XOR(pf_uint64_t left, pf_uint64_t right);

pf_uint64_t pf64_NOT(pf_uint64_t fnum);

pf_uint64_t pf64_lshift(pf_uint64_t fnum, int count);

pf_uint64_t pf64_rshift(pf_uint64_t fnum, int count);

pf_uint64_t pf64_clshift(pf_uint64_t fnum, int count);

pf_uint64_t pf64_crshift(pf_uint64_t fnum, int count);

uint32_t pf64_r(pf_uint64_t fnum);

uint32_t pf64_l(pf_uint64_t fnum);

pf_uint64_t to_pf64(uint32_t num);

pf_uint64_t to_pf64_2(uint32_t high, uint32_t low);

#else

#include "generic-internal.h"

typedef uint64_t pf_uint64_t;

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

#define pf64_r(n) ((uint32_t)(n))

#define pf64_l(n) ((uint32_t)((n) >> 32))

#define to_pf64(n) ((uint64_t)(n))

#define to_pf64_2(l, r) (((uint64_t)(r)) | ((uint64_t)(l) << 32));

#endif

#ifdef __cplusplus
}
#endif

#endif