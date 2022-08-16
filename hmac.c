#include "hmac.h"

#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"
#include "utils.h"

#define __pgfe_hmac_tmpl(name, nettle_name)                                                                            \
    inline void pgfe_hmac_##name(                                                                                      \
        const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[], const size_t length,           \
        pgfe_encode_t output[], const size_t out_length                                                                \
    ) {                                                                                                                \
        pgfe_hmac_generic(pgfe_##nettle_name##_encode_multiple, key, key_length, data, length, output, out_length);    \
    }

void pgfe_hmac_generic(
    pgfe_encode_multi_func *emfp, const pgfe_encode_t key[], const size_t key_length, const pgfe_encode_t data[],
    const size_t length, pgfe_encode_t output[], const size_t out_length
) {
    pgfe_encode_t k_i_pad[PGFE_MD5_BLOCK_SIZE], k_o_pad[PGFE_MD5_BLOCK_SIZE];
    size_t i, block_size = PGFE_MD5_BLOCK_SIZE;

    //// Initialize arrays (No need since the copy operations below will do that)
    // __pgfe_arrinit(k_i_pad, block_size);
    // __pgfe_arrinit(k_o_pad, block_size);

    __pgfe_arrcpy(k_i_pad, block_size, key, key_length);
    __pgfe_arrcpy(k_o_pad, block_size, key, key_length);

    for (i = 0; i < block_size; i++) {
        k_i_pad[i] ^= I_UNIT;
        k_o_pad[i] ^= O_UNIT;
    }

    pgfe_encode_t mid_hash[PGFE_MD5_DIGEST_SIZE];
    emfp(mid_hash, PGFE_MD5_DIGEST_SIZE, 2, k_i_pad, block_size, data, length);
    emfp(output, out_length, 2, k_o_pad, block_size, mid_hash, PGFE_MD5_DIGEST_SIZE);
}

__pgfe_hmac_tmpl(md5, md5);
__pgfe_hmac_tmpl(sha1, sha1);
__pgfe_hmac_tmpl(sha224, sha224);
__pgfe_hmac_tmpl(sha256, sha256);
__pgfe_hmac_tmpl(sha384, sha384);
__pgfe_hmac_tmpl(sha512, sha512);
__pgfe_hmac_tmpl(sha512_224, sha512_224);
__pgfe_hmac_tmpl(sha512_256, sha512_256);
__pgfe_hmac_tmpl(sha3_224, sha3_224);
__pgfe_hmac_tmpl(sha3_256, sha3_256);
__pgfe_hmac_tmpl(sha3_384, sha3_384);
__pgfe_hmac_tmpl(sha3_512, sha3_512);