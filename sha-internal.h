#ifndef LIBPGFE_SHA_INTERNAL_H
#define LIBPGFE_SHA_INTERNAL_H

#include "generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define sha_ch(x, y, z) (((x) & ((y) ^ (z))) ^ (z))
#define sha_maj(x, y, z) (((x) & ((y) | (z))) | ((y) & (z)))

#define sha_ch64(x, y, z) pf64_XOR(pf64_AND((x), pf64_XOR((y), (z))), (z))
#define sha_maj64(x, y, z) pf64_OR(pf64_AND((x), pf64_OR((y), (z))), pf64_AND((y), (z)))

#define sha_parity(x, y, z) ((x) ^ (y) ^ (z))

#define __PGFE_PADDING_HEADER 0x80

#ifdef __cplusplus
}
#endif

#endif