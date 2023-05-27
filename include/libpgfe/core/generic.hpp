/*
  libpgfe
  generic.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_HPP
#define LIBPGFE_GENERIC_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>
#include <unordered_map>

#include "libpgfe/algorithm-choice.h"
#include "libpgfe/exceptions.hpp"
#include "libpgfe/md5.h"
#include "libpgfe/sha1.h"
#include "libpgfe/sha2.h"
#include "libpgfe/sha3.h"

#define __PGFE_BATCH_SHAKE_CASES(name)                                                                                 \
    switch (cur_alg) {                                                                                                 \
        __PGFE_##name##_CASE(RawSHAKE128, rawshake128);                                                                \
        __PGFE_##name##_CASE(SHAKE128, shake128);                                                                      \
        __PGFE_##name##_CASE(RawSHAKE256, rawshake256);                                                                \
        __PGFE_##name##_CASE(SHAKE256, shake256);                                                                      \
    default:                                                                                                           \
        break;                                                                                                         \
    }

#define __PGFE_INIT_SIZE_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        digsz = PGFE_##alg##_DIGEST_SIZE;                                                                              \
        blocksz = PGFE_##alg##_BLOCK_SIZE;                                                                             \
        break

#define __PGFE_INIT_CTXP_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        pgfe_##name##_init((pgfe_##name##_ctx *)ctx);                                                                  \
        break

#define __PGFE_INIT_CTX_CASE(alg, name)                                                                                \
    case alg:                                                                                                          \
        pgfe_##name##_init(&ctx);                                                                                      \
        break

#define __PGFE_SET_CTXP_CASE(alg, name)                                                                                \
    case alg:                                                                                                          \
        ctx = new pgfe_##name##_ctx;                                                                                   \
        break

#define __PGFE_FREE_CTXP_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        delete (pgfe_##name##_ctx *)ctx;                                                                               \
        break

namespace libpgfe {

static const std::unordered_map<std::string, pgfe_algorithm_choice> pgfe_option_map = {
    {"sha1",        SHA1       },
    {"SHA1",        SHA1       },
    {"sha224",      SHA224     },
    {"SHA224",      SHA224     },
    {"sha256",      SHA256     },
    {"SHA256",      SHA256     },
    {"sha384",      SHA384     },
    {"SHA384",      SHA384     },
    {"sha512",      SHA512     },
    {"SHA512",      SHA512     },
    {"sha512_224",  SHA512_224 },
    {"SHA512_224",  SHA512_224 },
    {"sha512_256",  SHA512_256 },
    {"SHA512_256",  SHA512_256 },
    {"sha3_224",    SHA3_224   },
    {"SHA3_224",    SHA3_224   },
    {"sha3_256",    SHA3_256   },
    {"SHA3_256",    SHA3_256   },
    {"sha3_384",    SHA3_384   },
    {"SHA3_384",    SHA3_384   },
    {"sha3_512",    SHA3_512   },
    {"SHA3_512",    SHA3_512   },
    {"shake128",    SHAKE128   },
    {"SHAKE128",    SHAKE128   },
    {"rawshake128", RawSHAKE128},
    {"RawSHAKE128", RawSHAKE128},
    {"shake256",    SHAKE256   },
    {"SHAKE256",    SHAKE256   },
    {"rawshake256", RawSHAKE256},
    {"RawSHAKE256", RawSHAKE256},
    {"md5",         MD5        },
    {"MD5",         MD5        },
};

static const std::unordered_map<pgfe_algorithm_choice, size_t> pgfe_digest_length = {
    {SHA1,        PGFE_SHA1_DIGEST_SIZE       },
    {SHA224,      PGFE_SHA224_DIGEST_SIZE     },
    {SHA256,      PGFE_SHA256_DIGEST_SIZE     },
    {SHA384,      PGFE_SHA384_DIGEST_SIZE     },
    {SHA512,      PGFE_SHA512_DIGEST_SIZE     },
    {SHA512_224,  PGFE_SHA512_224_DIGEST_SIZE },
    {SHA512_256,  PGFE_SHA512_256_DIGEST_SIZE },
    {SHA3_224,    PGFE_SHA3_224_DIGEST_SIZE   },
    {SHA3_256,    PGFE_SHA3_256_DIGEST_SIZE   },
    {SHA3_384,    PGFE_SHA3_384_DIGEST_SIZE   },
    {SHA3_512,    PGFE_SHA3_512_DIGEST_SIZE   },
    {MD5,         PGFE_MD5_DIGEST_SIZE        },
    {SHAKE128,    PGFE_SHAKE128_DIGEST_SIZE   },
    {RawSHAKE128, PGFE_RawSHAKE128_DIGEST_SIZE},
    {SHAKE256,    PGFE_SHAKE256_DIGEST_SIZE   },
    {RawSHAKE256, PGFE_RawSHAKE256_DIGEST_SIZE},
};

static const std::unordered_map<pgfe_algorithm_choice, size_t> pgfe_block_length = {
    {SHA1,        PGFE_SHA1_BLOCK_SIZE       },
    {SHA224,      PGFE_SHA224_BLOCK_SIZE     },
    {SHA256,      PGFE_SHA256_BLOCK_SIZE     },
    {SHA384,      PGFE_SHA384_BLOCK_SIZE     },
    {SHA512,      PGFE_SHA512_BLOCK_SIZE     },
    {SHA512_224,  PGFE_SHA512_224_BLOCK_SIZE },
    {SHA512_256,  PGFE_SHA512_256_BLOCK_SIZE },
    {SHA3_224,    PGFE_SHA3_224_BLOCK_SIZE   },
    {SHA3_256,    PGFE_SHA3_256_BLOCK_SIZE   },
    {SHA3_384,    PGFE_SHA3_384_BLOCK_SIZE   },
    {SHA3_512,    PGFE_SHA3_512_BLOCK_SIZE   },
    {MD5,         PGFE_MD5_BLOCK_SIZE        },
    {SHAKE128,    PGFE_SHAKE128_BLOCK_SIZE   },
    {RawSHAKE128, PGFE_RawSHAKE128_BLOCK_SIZE},
    {SHAKE256,    PGFE_SHAKE256_BLOCK_SIZE   },
    {RawSHAKE256, PGFE_RawSHAKE256_BLOCK_SIZE},
};

// String to algorithm choice type

pgfe_algorithm_choice _algstr(const char *cs);
pgfe_algorithm_choice _algstr(std::string cpp_s);

inline pgfe_algorithm_choice operator"" _pgfe_alg(const char *str, size_t size) {
    return _algstr(str);
}

} // namespace libpgfe

#endif