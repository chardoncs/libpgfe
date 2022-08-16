#ifndef LIBPGFE_HMAC_H
#define LIBPGFE_HMAC_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

const pgfe_encode_t I_UNIT = 0x36, O_UNIT = 0x5c;

void pgfe_hmac_generic(
    pgfe_encode_multi_func *emfp, const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[],
    const size_t length, pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_md5(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha1(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha224(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha256(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha384(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha512(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha512_224(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha512_256(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha3_224(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha3_256(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha3_384(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

void pgfe_hmac_sha3_512(
    const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,
    pgfe_encode_t output[], const size_t out_length
);

#ifdef __cplusplus
}
#endif

#endif