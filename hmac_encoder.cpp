#include "hmac_encoder.hpp"

#include <cstring>
#include <stdexcept>

using namespace chardon55::PGFE;

#define __PGFE_FUNC_SET_CASE(alg, name)                                                                                \
    case alg:                                                                                                          \
        encode_func = pgfe_##name##_encode_multiple;                                                                   \
        break

void HMACEncoder::destroy_key() {
    if (!key) return;

    delete key;
    key = nullptr;
    key_len = 0;
}

void HMACEncoder::destroy_data() {
    if (!data) return;

    delete data;
    data = nullptr;
    data_len = 0;
}

HMACEncoder::HMACEncoder() {
    key = data = nullptr;
    key_len = data_len = 0;
}

HMACEncoder::~HMACEncoder() {
    destroy_key();
    destroy_data();
}

void HMACEncoder::after_change_alg() {
    __PGFE_BATCH_CASES(FUNC_SET)
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

void HMACEncoder::set_key(const std::string &cpp_s) {
    set_key((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

void HMACEncoder::update(const pgfe_encode_t sequence[], size_t length) {
    destroy_data();
    data = new pgfe_encode_t[length + 1];
    memcpy(data, sequence, length);
    data[length] = 0;
    data_len = length;
}

void HMACEncoder::update(const char cs[]) {
    update((pgfe_encode_t *)cs, strlen(cs));
}

void HMACEncoder::update(const std::string &cpp_s) {
    update((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

void HMACEncoder::get_digest(pgfe_encode_t out[], size_t length) {}