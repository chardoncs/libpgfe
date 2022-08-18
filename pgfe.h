#ifndef LIBPGFE_PGFE_H
#define LIBPGFE_PGFE_H

#include "algorithm-choice.h"
#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum pgfe_algorithm_choice pgfe_alg_option_t;

void pgfe_encode(const pgfe_alg_option_t algorithm, const pgfe_encode_t input[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif