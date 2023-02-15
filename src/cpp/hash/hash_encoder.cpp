/*
  libpgfe
  hash_encoder.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "hash_encoder.hpp"

#include <cstring>
#include <stdexcept>

#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"

#include "utils.h"

#define __PGFE_CTX_CREATE_CASE(alg, name)                                                                              \
    case alg:                                                                                                          \
        this->ctx = (void *)new pgfe_##name##_ctx;                                                                     \
        break

#define __PGFE_CTX_DELETE_CASE(alg, name)                                                                              \
    case alg:                                                                                                          \
        delete (pgfe_##name##_ctx *)ctx;                                                                               \
        break

#define __PGFE_INIT_FUNC_CALL_CASE(alg, name)                                                                          \
    case alg:                                                                                                          \
        pgfe_##name##_init((pgfe_##name##_ctx *)ctx);                                                                  \
        break

#define __PGFE_UPDATE_FUNC_CALL3_CASE(alg, name)                                                                       \
    case alg:                                                                                                          \
        pgfe_##name##_update((pgfe_##name##_ctx *)ctx, sequence, length);                                              \
        break

#define __PGFE_DIGEST_FUNC_CALL_CASE(alg, name)                                                                        \
    case alg:                                                                                                          \
        pgfe_##name##_digest((pgfe_##name##_ctx *)ctx, seq);                                                           \
        break

#define __PGFE_DIGEST_FUNC_CALL_LIMIT_CASE(alg, name)                                                                  \
    case alg:                                                                                                          \
        pgfe_##name##_digest((pgfe_##name##_ctx *)ctx, seq, bitlength);                                                \
        break

using namespace libpgfe;

void HashEncoder::destroy_context() {
    if (!ctx) return;

    __PGFE_BATCH_CASES(cur_alg, CTX_DELETE)
}

void HashEncoder::before_change_alg() {
    destroy_context();
}

void HashEncoder::load_algorithm() {
    __PGFE_BATCH_CASES(cur_alg, CTX_CREATE)
    __PGFE_BATCH_CASES(cur_alg, INIT_FUNC_CALL)
    __PGFE_BATCH_CASES(cur_alg, INIT_SIZE)
}

void HashEncoder::reset() {
    destroy_context();
    load_algorithm();
}

void HashEncoder::init() {
    reset();
}

HashEncoder::HashEncoder(pgfe_algorithm_choice choice) {
    select_algorithm(choice);
    init();
}

HashEncoder::~HashEncoder() {
    destroy_context();
}

void HashEncoder::update(const pgfe_encode_t sequence[], size_t length) {
    __PGFE_BATCH_CASES(cur_alg, UPDATE_FUNC_CALL3)
}

inline void HashEncoder::update(const char cs[]) {
    return this->AbstractHashEncoder::update(cs);
}

inline void HashEncoder::update(std::string &cpp_s) {
    return this->AbstractHashEncoder::update(cpp_s);
}

inline void HashEncoder::update(SequentialData &sd) {
    return this->AbstractHashEncoder::update(sd);
}

const SequentialData *HashEncoder::get_digest(uint64_t bitlength) {
    bool shake_flag = this->cur_alg == SHAKE128 || this->cur_alg == RawSHAKE128 || this->cur_alg == SHAKE256 ||
                      this->cur_alg == RawSHAKE256;
    uint64_t in_len = to_byte(bitlength) + bit_rem(bitlength);

    if (!bitlength) {
        if (this->cur_alg == SHAKE128 || this->cur_alg == RawSHAKE128) {
            bitlength = 256;
        }
        else if (this->cur_alg == SHAKE256 || this->cur_alg == RawSHAKE256) {
            bitlength = 512;
        }
    }

    size_t length = shake_flag ? in_len : in_len < digsz && bitlength ? in_len : digsz;
    pgfe_encode_t seq[length];

    if (shake_flag) {
        __PGFE_BATCH_SHAKE_CASES(DIGEST_FUNC_CALL_LIMIT)
    }
    else {
        __PGFE_BATCH_CASES_SP(cur_alg, DIGEST_FUNC_CALL)
    }

    out = std::make_unique<SequentialData>((const pgfe_encode_t *)seq, length);
    return (const SequentialData *)out.get();
}