/*
  libpgfe
  generic.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_HPP
#define LIBPGFE_GENERIC_HPP
#ifdef __cplusplus

#include <string>
#include <unordered_map>

#include "algorithm-choice.h"
#include "exceptions.hpp"
#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"

#define __PGFE_BATCH_CASES(name)                                                                                       \
    switch (cur) {                                                                                                     \
        __PGFE_##name##_CASE(MD5, md5);                                                                                \
        __PGFE_##name##_CASE(SHA1, sha1);                                                                              \
        __PGFE_##name##_CASE(SHA224, sha224);                                                                          \
        __PGFE_##name##_CASE(SHA256, sha256);                                                                          \
        __PGFE_##name##_CASE(SHA384, sha384);                                                                          \
        __PGFE_##name##_CASE(SHA512, sha512);                                                                          \
        __PGFE_##name##_CASE(SHA512_224, sha512_224);                                                                  \
        __PGFE_##name##_CASE(SHA512_256, sha512_256);                                                                  \
        __PGFE_##name##_CASE(SHA3_224, sha3_224);                                                                      \
        __PGFE_##name##_CASE(SHA3_256, sha3_256);                                                                      \
        __PGFE_##name##_CASE(SHA3_384, sha3_384);                                                                      \
        __PGFE_##name##_CASE(SHA3_512, sha3_512);                                                                      \
    default:                                                                                                           \
        throw std::invalid_argument("Unknown option");                                                                 \
        break;                                                                                                         \
    }

#define __PGFE_MTFUNC_SET_CASE(alg, name)                                                                              \
    case alg:                                                                                                          \
        encode_func = pgfe_##name##_encode_multiple;                                                                   \
        break

#define __PGFE_INIT_SIZE_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        digsz = PGFE_##alg##_DIGEST_SIZE;                                                                              \
        blocksz = PGFE_##alg##_BLOCK_SIZE;                                                                             \
        break

namespace chardon55 {
namespace PGFE {

static std::unordered_map<std::string, pgfe_algorithm_choice> pgfe_option_map = {
    {"sha1",       SHA1      },
    {"SHA1",       SHA1      },
    {"sha224",     SHA224    },
    {"SHA224",     SHA224    },
    {"sha256",     SHA256    },
    {"SHA256",     SHA256    },
    {"sha384",     SHA384    },
    {"SHA384",     SHA384    },
    {"sha512",     SHA512    },
    {"SHA512",     SHA512    },
    {"sha512_224", SHA512_224},
    {"SHA512_224", SHA512_224},
    {"sha512_256", SHA512_256},
    {"SHA512_256", SHA512_256},
    {"sha3_224",   SHA3_224  },
    {"SHA3_224",   SHA3_224  },
    {"sha3_256",   SHA3_256  },
    {"SHA3_256",   SHA3_256  },
    {"sha3_384",   SHA3_384  },
    {"SHA3_384",   SHA3_384  },
    {"sha3_512",   SHA3_512  },
    {"SHA3_512",   SHA3_512  },
    {"md5",        MD5       },
    {"MD5",        MD5       },
};

static std::unordered_map<pgfe_algorithm_choice, size_t> pgfe_digest_length = {

    {SHA1,       PGFE_SHA1_DIGEST_SIZE      },
    {SHA224,     PGFE_SHA224_DIGEST_SIZE    },
    {SHA256,     PGFE_SHA256_DIGEST_SIZE    },
    {SHA384,     PGFE_SHA384_DIGEST_SIZE    },
    {SHA512,     PGFE_SHA512_DIGEST_SIZE    },
    {SHA512_224, PGFE_SHA512_224_DIGEST_SIZE},
    {SHA512_256, PGFE_SHA512_256_DIGEST_SIZE},
    {SHA3_224,   PGFE_SHA3_224_DIGEST_SIZE  },
    {SHA3_256,   PGFE_SHA3_256_DIGEST_SIZE  },
    {SHA3_384,   PGFE_SHA3_384_DIGEST_SIZE  },
    {SHA3_512,   PGFE_SHA3_512_DIGEST_SIZE  },
    {MD5,        PGFE_MD5_DIGEST_SIZE       },
};

static std::unordered_map<pgfe_algorithm_choice, size_t> pgfe_block_length = {

    {SHA1,       PGFE_SHA1_BLOCK_SIZE      },
    {SHA224,     PGFE_SHA224_BLOCK_SIZE    },
    {SHA256,     PGFE_SHA256_BLOCK_SIZE    },
    {SHA384,     PGFE_SHA384_BLOCK_SIZE    },
    {SHA512,     PGFE_SHA512_BLOCK_SIZE    },
    {SHA512_224, PGFE_SHA512_224_BLOCK_SIZE},
    {SHA512_256, PGFE_SHA512_256_BLOCK_SIZE},
    {SHA3_224,   PGFE_SHA3_224_BLOCK_SIZE  },
    {SHA3_256,   PGFE_SHA3_256_BLOCK_SIZE  },
    {SHA3_384,   PGFE_SHA3_384_BLOCK_SIZE  },
    {SHA3_512,   PGFE_SHA3_512_BLOCK_SIZE  },
    {MD5,        PGFE_MD5_BLOCK_SIZE       },
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif