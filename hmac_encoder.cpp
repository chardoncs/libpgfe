/*
  libpgfe
  hmac_encoder.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "hmac_encoder.hpp"

#include <cstring>

#include "hmac.h"

using namespace chardon55::PGFE;

void HMACEncoder::destroy_key() {
    if (!key) return;

    delete[] key;
    key = nullptr;
    key_len = 0;
}

void HMACEncoder::destroy_data() {
    if (!data) return;

    delete[] data;
    data = nullptr;
    data_len = 0;
}

HMACEncoder::HMACEncoder() {
    key = data = output = nullptr;
    key_len = data_len = 0;
    encode_func = nullptr;

    select_algorithm(SHA1);
}

HMACEncoder::~HMACEncoder() {
    destroy_key();
    destroy_data();

    if (output) {
        delete[] output;
    }
}

void HMACEncoder::after_change_alg() {
    __PGFE_BATCH_CASES(MTFUNC_SET)
    __PGFE_BATCH_CASES(INIT_SIZE)

    if (output) {
        delete[] output;
    }

    output = new pgfe_encode_t[digsz + 1];
}

void HMACEncoder::set_key(const pgfe_encode_t sequence[], size_t length) {
    destroy_key();
    key = new pgfe_encode_t[length + 1];
    memcpy(key, sequence, length);
    key[length] = 0;
    key_len = length;
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
    destroy_data();
    data = new pgfe_encode_t[length + 1];
    memcpy(data, sequence, length);
    data[length] = 0;
    data_len = length;
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

SequentialData HMACEncoder::get_digest() {
    if (!encode_func || !key || !data) {
        throw NotInitializedException();
    }

    pgfe_hmac_generic(this->encode_func, blocksz, digsz, key, key_len, data, data_len, output, digsz);

    SequentialData sd(output, digsz);
    return sd;
}