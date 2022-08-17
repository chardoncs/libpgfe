#ifndef LIBPGFE_GENERIC_INTERNAL_H
#define LIBPGFE_GENERIC_INTERNAL_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_HEX_UNKNOWN_CHAR 0xF1

void __pgfe_arrinit(pgfe_encode_t arr[], const size_t size);

void __pgfe_arrcpy(pgfe_encode_t dest[], const size_t dest_s, const pgfe_encode_t src[], const size_t src_s);

void __pgfe_ch2hex(const char ch, pgfe_encode_t *hex);

#ifdef __cplusplus
}
#endif

#endif