#ifndef LIBPGFE_KECCAK_BACKEND_H
#define LIBPGFE_KECCAK_BACKEND_H

#include <stddef.h>
#include <stdint.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t pgfe_keccak_unit_t;

// typedef uint32_t

// PKCS = PGFE Keccak Conversion Structure
#define __PKCS_SIZE 8
#define __PKCS_UNIT_LEN 4

#ifdef __cplusplus
}
#endif

#endif