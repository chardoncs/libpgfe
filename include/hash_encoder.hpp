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

#include "backend_cpp/abstract_hash_encoder.hpp"

#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

// Libpgfe - Hash Encoder
class HashEncoder : public AbstractHashEncoder
{

private:
    void *ctx = nullptr;

    SequentialData *out = nullptr;

    void load_algorithm();

    void destroy_context();
    void destroy_output();

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

    const SequentialData *get_digest(uint64_t bitlength = 0);
};

} // namespace PGFE
} // namespace chardon55

#endif