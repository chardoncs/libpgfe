/*
  libpgfe
  hash_encoder.hpp

  Hash encoder

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_CORE_HASH_ENCODER_HPP
#define LIBPGFE_CORE_HASH_ENCODER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include "libpgfe/core/abstract_hash_encoder.hpp"

#include <memory>

#include "generic.hpp"

namespace libpgfe {

class HashEncoder : public AbstractHashEncoder
{

private:
    void *ctx = nullptr;

    std::unique_ptr<SequentialData> out;

    void load_algorithm();

    void destroy_context();

    void init();

protected:
    void before_change_alg();

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

} // namespace libpgfe

#endif