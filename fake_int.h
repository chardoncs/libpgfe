#ifndef LIBPGFE_FAKE_INT_H
#define LIBPGFE_FAKE_INT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pgfe_fake_uint64
{
    uint32_t l, r;
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

#ifdef __cplusplus
}
#endif

#endif