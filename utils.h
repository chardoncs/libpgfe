#ifndef LIBPGFE_UTILS_H
#define LIBPGFE_UTILS_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

void __pgfe_arrinit(pgfe_encode_t arr[], const size_t size);

void __pgfe_arrcpy(pgfe_encode_t dest[], const size_t dest_s, const pgfe_encode_t src[], const size_t src_s);

#ifdef __cplusplus
}
#endif

#endif