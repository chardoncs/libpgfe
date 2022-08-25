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

using namespace chardon55::PGFE;

void HashEncoder::destroy_context() {
    if (!ctx) return;

    __PGFE_BATCH_CASES(CTX_DELETE)
}

void HashEncoder::before_change_alg() {
    destroy_context();
}

void HashEncoder::after_change_alg() {
    load_algorithm();
}

void HashEncoder::load_algorithm() {
    __PGFE_BATCH_CASES(CTX_CREATE)
    __PGFE_BATCH_CASES(INIT_FUNC_CALL)
    __PGFE_BATCH_CASES(INIT_SIZE)

    if (seq) {
        delete[] seq;
    }
    seq = new pgfe_encode_t[digsz + 1];
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

HashEncoder::HashEncoder(std::string &choice) {
    select_algorithm(choice);
    init();
}

HashEncoder::~HashEncoder() {
    destroy_context();
    if (seq) {
        delete[] seq;
    }
}

void HashEncoder::update(const pgfe_encode_t sequence[], size_t length) {
    __PGFE_BATCH_CASES(UPDATE_FUNC_CALL3)
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

SequentialData HashEncoder::get_digest() {
    __PGFE_BATCH_CASES(DIGEST_FUNC_CALL)
    seq[digsz] = 0;

    SequentialData sd(seq, digsz);
    return sd;
}