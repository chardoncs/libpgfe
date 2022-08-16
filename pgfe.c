#include "pgfe.h"

#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"
#include "templates.c"

#define __PGFE_ENCODE_TL(order, name)                                                                                  \
    case order:                                                                                                        \
        efp = pgfe_##name##_encode_default;                                                                            \
        break

#define __PGFE_DEFAULT_CASE                                                                                            \
    default:                                                                                                           \
        break

void pgfe_encode(const pgfe_alg_option_t algorithm, const pgfe_encode_t input[], pgfe_encode_t output[]) {

    pgfe_encode_func *efp = NULL;

    switch (algorithm) {
        __PGFE_ENCODE_TL(PGFE_MD5, md5);
        __PGFE_ENCODE_TL(PGFE_SHA1, sha1);
        __PGFE_ENCODE_TL(PGFE_SHA224, sha224);
        __PGFE_ENCODE_TL(PGFE_SHA256, sha256);
        __PGFE_ENCODE_TL(PGFE_SHA384, sha384);
        __PGFE_ENCODE_TL(PGFE_SHA512, sha512);
        __PGFE_ENCODE_TL(PGFE_SHA3_224, sha3_224);
        __PGFE_ENCODE_TL(PGFE_SHA3_256, sha3_256);
        __PGFE_ENCODE_TL(PGFE_SHA3_384, sha3_384);
        __PGFE_ENCODE_TL(PGFE_SHA3_512, sha3_512);
        __PGFE_DEFAULT_CASE;
    }

    if (!efp) {
        return;
    }

    efp(input, output);
}