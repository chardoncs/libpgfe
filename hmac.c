/*
  libpgfe
  hmac.c

  Copyright (c) 2022 Charles Dong
*/

#include "hmac.h"

#include "generic-internal.h"
#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"

#define __pgfe_hmac_tmpl(name, upper)                                                                                  \
    inline void pgfe_hmac_##name(                                                                                      \
        const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length,                       \
        pgfe_encode_t output[]                                                                                         \
    ) {                                                                                                                \
        pgfe_hmac_generic(                                                                                             \
            pgfe_##name##_encode_multiple, PGFE_##upper##_BLOCK_SIZE, PGFE_##upper##_DIGEST_SIZE, key, key_length,     \
            data, length, output                                                                                       \
        );                                                                                                             \
    }

void pgfe_hmac_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length,
    pgfe_encode_t output[]
) {
    pgfe_encode_t k_i_pad[block_size], k_o_pad[block_size];
    size_t i;

    //// Initialize arrays (No need since the copy operations below will do that)
    // __pgfe_arrinit(k_i_pad, block_size);
    // __pgfe_arrinit(k_o_pad, block_size);

    __pgfe_arrcpy(k_i_pad, block_size, key, key_length);
    __pgfe_arrcpy(k_o_pad, block_size, key, key_length);

    for (i = 0; i < block_size; i++) {
        k_i_pad[i] ^= I_UNIT;
        k_o_pad[i] ^= O_UNIT;
    }

    pgfe_encode_t mid_hash[digest_size + 1];

    func(mid_hash, 2, k_i_pad, block_size, data, length);
    func(output, 2, k_o_pad, block_size, mid_hash, digest_size);

    // Wipe buffers' data from the RAM for security consideration
    memset(k_i_pad, 0, block_size);
    memset(k_o_pad, 0, block_size);
}

__pgfe_hmac_tmpl(md5, MD5);
__pgfe_hmac_tmpl(sha1, SHA1);
__pgfe_hmac_tmpl(sha224, SHA224);
__pgfe_hmac_tmpl(sha256, SHA256);
__pgfe_hmac_tmpl(sha384, SHA384);
__pgfe_hmac_tmpl(sha512, SHA512);
__pgfe_hmac_tmpl(sha512_224, SHA512_224);
__pgfe_hmac_tmpl(sha512_256, SHA512_256);
__pgfe_hmac_tmpl(sha3_224, SHA3_224);
__pgfe_hmac_tmpl(sha3_256, SHA3_256);
__pgfe_hmac_tmpl(sha3_384, SHA3_384);
__pgfe_hmac_tmpl(sha3_512, SHA3_512);