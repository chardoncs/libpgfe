/*
  libpgfe
  sha384.c

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

#include "sha2.h"
#include "templates.c"

__PGFE_FRONTEND_GEN(sha384, sha384);
__PGFE_FRONTEND_DEFAULT_GEN(sha384, PGFE_SHA384_DIGEST_SIZE);