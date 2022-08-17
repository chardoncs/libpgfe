#ifndef LIBPGFE_GENERIC_INTERNAL_H
#define LIBPGFE_GENERIC_INTERNAL_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_HEX_UNKNOWN_CHAR 0xF1

void __pgfe_arrinit(pgfe_encode_t arr[], size_t size);

void __pgfe_arrcpy(pgfe_encode_t dest[], size_t dest_s, const pgfe_encode_t src[], size_t src_s);

void __pgfe_ch2hex(char ch, pgfe_encode_t *hex);

#ifdef __cplusplus
}
#endif

#endif