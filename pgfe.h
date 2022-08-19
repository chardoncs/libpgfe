/*
  libpgfe
  pgfe.h

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

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