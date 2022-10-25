/*
  libpgfe
  hmac_encoder.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "hmac_encoder.hpp"

#include <cstring>

#define __PGFE_HMAC_INIT_CTX_CASE(alg, name)                                                                           \
    case alg:                                                                                                          \
        pgfe_hmac_##name##_init(&ctx.name);                                                                            \
        break

#define __PGFE_HMAC_DIGEST_CASE(alg, name)                                                                             \
    case alg: {                                                                                                        \
        pgfe_encode_t out[PGFE_##alg##_DIGEST_SIZE];                                                                   \
        pgfe_hmac_##name##_digest(&ctx.name, out);                                                                     \
        output = new SequentialData(out, PGFE_##alg##_DIGEST_SIZE);                                                    \
    } break

#define __PGFE_HMAC_SET_KEY_CASE(alg, name)                                                                            \
    case alg:                                                                                                          \
        pgfe_hmac_##name##_set_key(&ctx.name, sequence, length);                                                       \
        break

#define __PGFE_HMAC_ADD_DATA_CASE(alg, name)                                                                           \
    case alg:                                                                                                          \
        pgfe_hmac_##name##_update(&ctx.name, sequence, length);                                                        \
        break

using namespace chardon55::PGFE;

void HMACEncoder::destroy_output() {
    if (output) {
        delete output;
    }
}

HMACEncoder::HMACEncoder(pgfe_algorithm_choice algorithm, const pgfe_encode_t sequence[], size_t length) {
    select_algorithm(algorithm);
    set_key(sequence, length);
}

HMACEncoder::HMACEncoder(pgfe_algorithm_choice algorithm, const char cs[]) {
    select_algorithm(algorithm);
    set_key(cs);
}

HMACEncoder::HMACEncoder(pgfe_algorithm_choice algorithm, std::string &cpp_s) {
    select_algorithm(algorithm);
    set_key(cpp_s);
}

HMACEncoder::HMACEncoder(pgfe_algorithm_choice algorithm, SequentialData &sd) {
    select_algorithm(algorithm);
    set_key(sd);
}

HMACEncoder::~HMACEncoder() {
    destroy_output();
}

void HMACEncoder::after_change_alg() {
    __PGFE_BATCH_CASES_SP(HMAC_INIT_CTX)
    __PGFE_BATCH_CASES_SP(INIT_SIZE)
}

void HMACEncoder::set_key(const pgfe_encode_t sequence[], size_t length) {
    __PGFE_BATCH_CASES_SP(HMAC_SET_KEY)
}

void HMACEncoder::set_key(const char cs[]) {
    set_key((pgfe_encode_t *)cs, strlen(cs));
}

void HMACEncoder::set_key(std::string &cpp_s) {
    set_key((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

void HMACEncoder::set_key(SequentialData &sd) {
    size_t sz;
    set_key(sd.to_pgfe_seq(sz), sz);
}

void HMACEncoder::update(const pgfe_encode_t sequence[], size_t length) {
    __PGFE_BATCH_CASES_SP(HMAC_ADD_DATA)
}

inline void HMACEncoder::update(const char cs[]) {
    this->AbstractHashEncoder::update(cs);
}

inline void HMACEncoder::update(std::string &cpp_s) {
    this->AbstractHashEncoder::update(cpp_s);
}

inline void HMACEncoder::update(SequentialData &sd) {
    this->AbstractHashEncoder::update(sd);
}

SequentialData *HMACEncoder::get_digest() {
    if (!output) {
        __PGFE_BATCH_CASES_SP(HMAC_DIGEST)
    }

    return output->copy();
}