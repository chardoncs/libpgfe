/*
  libpgfe
  algorithm-choice.h

  Copyright (c) 2022 Charles Dong
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
    SHA3_512,
    // RawSHAKE-128
    RawSHAKE128,
    // SHAKE-128
    SHAKE128,
    // RawSHAKE-256
    RawSHAKE256,
    // SHAKE-256
    SHAKE256,
};

#ifdef __cplusplus
}
#endif

#endif