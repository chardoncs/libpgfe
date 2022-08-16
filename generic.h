#ifndef LIBPGFE_GENERIC_H
#define LIBPGFE_GENERIC_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BUFFER_SIZE 1024

// File reading behavior options
#define PGFE_FR_CURRENT_END 0
#define PGFE_FR_START_END -1

typedef uint8_t pgfe_encode_t;

// Convert SHA hash to a string represented by hexadecimal numbers
void pgfe_hash_to_hex_string(const pgfe_encode_t hash[], const size_t hash_length, char out[]);

// Print SHA hash
void pgfe_print_hash(const pgfe_encode_t hash[], const size_t length);

#ifdef __cplusplus
}
#endif

#endif