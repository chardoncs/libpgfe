#ifndef LIBPGFE_SHA_INTERNAL_H
#define LIBPGFE_SHA_INTERNAL_H

#include "generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define sha_ch(x, y, z) (((x) & ((y) ^ (z))) ^ (z))
#define sha_maj(x, y, z) (((x) & ((y) | (z))) | ((y) & (z)))

#define sha_parity(x, y, z) ((x) ^ (y) ^ (z))

#ifdef __cplusplus
}
#endif

#endif