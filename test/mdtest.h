/*
  libpgfe
  mdtest.h

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

#include "test.h"

#include "../md5.h"
#include "../utils.h"

void md5test(ARGS) {
    pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

    pgfe_md5_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
}