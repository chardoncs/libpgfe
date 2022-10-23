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
        pgfe_hmac_##name##_set_key(&ctx.name, key->to_pgfe_seq(), key->length());                                      \
        break

#define __PGFE_HMAC_ADD_DATA_CASE(alg, name)                                                                           \
    case alg:                                                                                                          \
        for (SequentialData * item : *data_vec) {                                                                      \
            pgfe_hmac_##name##_update(&ctx.name, item->to_pgfe_seq(), item->length());                                 \
        }                                                                                                              \
        break

using namespace chardon55::PGFE;

void HMACEncoder::destroy_key() {
    if (!key) return;

    delete key;
    key = nullptr;
}

void HMACEncoder::destroy_data() {
    if (!data_vec) return;

    while (data_vec->size()) {
        delete data_vec->back();
        data_vec->pop_back();
    }
    delete data_vec;
    data_vec = nullptr;
}

void HMACEncoder::destroy_output() {
    if (output) {
        delete output;
    }
}

HMACEncoder::HMACEncoder() {
    key = output = nullptr;
    data_vec = new std::vector<SequentialData *>();

    select_algorithm(SHA1);
}

HMACEncoder::~HMACEncoder() {
    destroy_key();
    destroy_data();
    destroy_output();
}

void HMACEncoder::after_change_alg() {
    __PGFE_BATCH_CASES_SP(INIT_SIZE)

    destroy_output();
}

void HMACEncoder::set_key(const pgfe_encode_t sequence[], size_t length) {
    destroy_key();
    key = new SequentialData(sequence, length);
    destroy_output();
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
    data_vec->push_back(new SequentialData(sequence, length));
    destroy_output();
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
    if (!key || !data_vec) {
        throw new NotInitializedException();
    }

    if (!output) {
        __PGFE_BATCH_CASES_SP(HMAC_INIT_CTX)
        __PGFE_BATCH_CASES_SP(HMAC_SET_KEY)
        __PGFE_BATCH_CASES_SP(HMAC_ADD_DATA)
        __PGFE_BATCH_CASES_SP(HMAC_DIGEST)
    }

    return output->copy();
}