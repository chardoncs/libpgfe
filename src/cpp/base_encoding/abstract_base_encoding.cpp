/*
  libpgfe
  abstract_base_encoding.cpp

  Copyright (c) 2022 Charles Dong
*/

#include <cmath>
#include <cstring>

#include "backend_cpp/abstract_base_encoding.hpp"

#define PGFE_SPACE_MULTIPLE 1.2

using namespace chardon55::PGFE;

void AbstractBaseEncoding::init() {
    init_base_function(encode_f, decode_f);
    init_size(unitsz, chunksz, bitsz, alphabetsz);
}

std::string AbstractBaseEncoding::encode(const pgfe_encode_t *pgfe_c_seq, size_t length) {
    size_t sz = (size_t)ceil(length * ((double)to_bit(sizeof(pgfe_encode_t)) / (double)bitsz) * PGFE_SPACE_MULTIPLE);

    enc_mutex.lock();
    if (encsz <= sz) {
        en_cache = std::make_unique<char[]>(sz + 1);
        encsz = sz;
    }

    char *p = en_cache.get();
    sz = encode_f(pgfe_c_seq, length, p);
    en_cache[sz] = 0;

    std::string str(p);
    enc_mutex.unlock();
    return str;
}

std::string AbstractBaseEncoding::encode(const char *cs) {
    return encode((pgfe_encode_t *)cs, strlen(cs));
}

std::string AbstractBaseEncoding::encode(const std::string &cpp_s) {
    return encode((pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

std::string AbstractBaseEncoding::encode(const SequentialData &sd) {
    return encode(sd.to_pgfe_seq(), sd.length());
}

SequentialData AbstractBaseEncoding::decode(const char *base_cs) {
    size_t sz =
        (size_t)ceil(strlen(base_cs) * ((double)bitsz / (double)to_bit(sizeof(pgfe_encode_t))) * PGFE_SPACE_MULTIPLE);

    dec_mutex.lock();
    if (decsz <= sz) {
        de_cache = std::make_unique<pgfe_encode_t[]>(sz);
        decsz = sz;
    }

    pgfe_encode_t *p = de_cache.get();
    sz = decode_f(base_cs, p);
    de_cache[sz] = 0;

    SequentialData sd(p, sz);
    dec_mutex.unlock();
    return sd;
}

SequentialData AbstractBaseEncoding::decode(const std::string &cpp_s) {
    return decode(cpp_s.c_str());
}

base_short_size_t AbstractBaseEncoding::unit_size() const {
    return unitsz;
}

base_short_size_t AbstractBaseEncoding::chunk_size() const {
    return chunksz;
}

base_short_size_t AbstractBaseEncoding::bit_size() const {
    return bitsz;
}

base_short_size_t AbstractBaseEncoding::alphabet_size() const {
    return alphabetsz;
}