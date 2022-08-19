/*
  libpgfe
  algorithm-choice.h

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

#ifndef LIBPGFE_ALGORITHM_CHOICE_H
#define LIBPGFE_ALGORITHM_CHOICE_H

#ifdef __cplusplus
extern "C" {
#endif

// Choice for selecting algorithm
enum pgfe_algorithm_choice {
    // MD5
    MD5,
    // SHA1
    SHA1,
    // SHA224
    SHA224,
    // SHA256
    SHA256,
    // SHA384
    SHA384,
    // SHA512
    SHA512,
    // SHA512-224
    SHA512_224,
    // SHA512-256
    SHA512_256,
    // SHA3-224
    SHA3_224,
    // SHA3-256
    SHA3_256,
    // SHA3-384
    SHA3_384,
    // SHA3-512
    SHA3_512
};

#ifdef __cplusplus
}
#endif

#endif