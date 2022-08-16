#ifndef LIBPGFE_PGFE_H
#define LIBPGFE_PGFE_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_MD5 1
#define PGFE_SHA1 2
#define PGFE_SHA224 3
#define PGFE_SHA256 4
#define PGFE_SHA384 5
#define PGFE_SHA512 6
#define PGFE_SHA3_224 7
#define PGFE_SHA3_256 8
#define PGFE_SHA3_384 9
#define PGFE_SHA3_512 10

typedef int pgfe_alg_option_t;

void pgfe_encode(const pgfe_alg_option_t algorithm, const pgfe_encode_t input[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif