#include "hmac.h"

#include "generic-internal.h"
#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"

#define __pgfe_hmac_tmpl(name, nettle_name, upper)                                                                     \
    inline void pgfe_hmac_##name(                                                                                      \
        const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length,                       \
        pgfe_encode_t output[], size_t out_length                                                                      \
    ) {                                                                                                                \
        pgfe_hmac_generic(                                                                                             \
            pgfe_##nettle_name##_encode_multiple, PGFE_##upper##_BLOCK_SIZE, PGFE_##upper##_DIGEST_SIZE, key,          \
            key_length, data, length, output, out_length                                                               \
        );                                                                                                             \
    }

void pgfe_hmac_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length,
    pgfe_encode_t output[], size_t out_length
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

    pgfe_encode_t mid_hash[digest_size];

    func(mid_hash, digest_size, 2, k_i_pad, block_size, data, length);
    func(output, out_length, 2, k_o_pad, block_size, mid_hash, digest_size);
}

__pgfe_hmac_tmpl(md5, md5, MD5);
__pgfe_hmac_tmpl(sha1, sha1, SHA1);
__pgfe_hmac_tmpl(sha224, sha224, SHA224);
__pgfe_hmac_tmpl(sha256, sha256, SHA256);
__pgfe_hmac_tmpl(sha384, sha384, SHA384);
__pgfe_hmac_tmpl(sha512, sha512, SHA512);
__pgfe_hmac_tmpl(sha512_224, sha512_224, SHA512_224);
__pgfe_hmac_tmpl(sha512_256, sha512_256, SHA512_256);
__pgfe_hmac_tmpl(sha3_224, sha3_224, SHA3_224);
__pgfe_hmac_tmpl(sha3_256, sha3_256, SHA3_256);
__pgfe_hmac_tmpl(sha3_384, sha3_384, SHA3_384);
__pgfe_hmac_tmpl(sha3_512, sha3_512, SHA3_512);