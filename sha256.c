/*
  libpgfe
  sha256.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha2.h"
#include "templates.c"

__PGFE_FRONTEND_GEN(sha256, sha256);
__PGFE_FRONTEND_DEFAULT_GEN(sha256, PGFE_SHA256_DIGEST_SIZE);