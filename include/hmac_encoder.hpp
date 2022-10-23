/*
  libpgfe
  hmac_encoder.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_HMAC_ENCODER_HPP
#define LIBPGFE_HMAC_ENCODER_HPP
#ifdef __cplusplus

#include <vector>

#include "abstract_hash_encoder.hpp"
#include "generic.h"
#include "generic.hpp"
#include "hmac.h"

namespace chardon55 {
namespace PGFE {

class HMACEncoder : public AbstractHashEncoder
{
private:
    union
    {
        pgfe_hmac_md5_ctx md5;
        pgfe_hmac_sha1_ctx sha1;
        pgfe_hmac_sha224_ctx sha224;
        pgfe_hmac_sha256_ctx sha256;
        pgfe_hmac_sha384_ctx sha384;
        pgfe_hmac_sha512_ctx sha512;
        pgfe_hmac_sha512_224_ctx sha512_224;
        pgfe_hmac_sha512_256_ctx sha512_256;
        pgfe_hmac_sha3_224_ctx sha3_224;
        pgfe_hmac_sha3_256_ctx sha3_256;
        pgfe_hmac_sha3_384_ctx sha3_384;
        pgfe_hmac_sha3_512_ctx sha3_512;
    } ctx;

    size_t digsz, blocksz;

    SequentialData *key, *output;
    std::vector<SequentialData *> *data_vec;

    void destroy_key();
    void destroy_data();
    void destroy_output();

protected:
    void after_change_alg();

public:
    HMACEncoder();
    ~HMACEncoder();

    void set_key(const pgfe_encode_t sequence[], size_t length);
    void set_key(const char cs[]);
    void set_key(std::string &cpp_s);
    void set_key(SequentialData &sd);

    void update(const pgfe_encode_t sequence[], size_t length);
    void update(const char cs[]);
    void update(std::string &cpp_s);
    void update(SequentialData &sd);

    SequentialData *get_digest();

    size_t block_size() {
        return blocksz;
    }

    size_t digest_size() {
        return digsz;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif