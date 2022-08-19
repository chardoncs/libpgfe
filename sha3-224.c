/*
  libpgfe
  sha3-224.c

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

#include "sha3.h"
#include "templates.c"

__PGFE_FRONTEND_GEN(sha3_224, sha3_224);
__PGFE_FRONTEND_DEFAULT_GEN(sha3_224, PGFE_SHA3_224_DIGEST_SIZE);