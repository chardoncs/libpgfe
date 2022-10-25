/*
  libpgfe
  hash_encoder.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_HASH_ENCODER_HPP
#define LIBPGFE_HASH_ENCODER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include "abstract_hash_encoder.hpp"

#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

// Libpgfe - Hash Encoder
class HashEncoder : public AbstractHashEncoder
{

private:
    void *ctx = nullptr;

    size_t digsz, blocksz;
    pgfe_encode_t *seq = nullptr;

    void load_algorithm();

    void destroy_context();

    void init();

protected:
    void before_change_alg();
    void after_change_alg();

public:
    HashEncoder(pgfe_algorithm_choice algorithm);
    ~HashEncoder();

    void reset();

    void update(const pgfe_encode_t sequence[], size_t length);
    void update(const char cs[]);
    void update(std::string &cpp_s);
    void update(SequentialData &sd);

    SequentialData *get_digest(uint64_t bitlength = 0);

    size_t digest_size() {
        return digsz;
    }

    size_t block_size() {
        return blocksz;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif