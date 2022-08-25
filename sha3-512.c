/*
  libpgfe
  sha3-512.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha3.h"
#include "templates.c"

__PGFE_FRONTEND_GEN(sha3_512, sha3_512);
__PGFE_FRONTEND_DEFAULT_GEN(sha3_512, PGFE_SHA3_512_DIGEST_SIZE);