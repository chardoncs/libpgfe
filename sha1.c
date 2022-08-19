/*
  libpgfe
  sha1.c

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

#include "sha1.h"
#include "templates.c"

__PGFE_FRONTEND_GEN(sha1, sha1);
__PGFE_FRONTEND_DEFAULT_GEN(sha1, PGFE_SHA1_DIGEST_SIZE);