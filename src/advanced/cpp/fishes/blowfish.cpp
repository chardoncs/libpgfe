/*
  libpgfe
  blowfish.cpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/advanced/fishes/blowfish.hpp"

#include <cstring>
#include <memory>

using namespace libpgfe;

Blowfish::Blowfish(const SequentialData &key) : Blowfish(key.to_pgfe_seq(), key.length()) {}

Blowfish::Blowfish(const char key[]) : Blowfish((const pgfe_encode_t *)key, strlen(key)) {}

Blowfish::Blowfish(const pgfe_encode_t *key, size_t length) {
    pgfe_blowfish_init(&ctx, key, length);
}

Blowfish::Blowfish(const std::string &key) : Blowfish(key.c_str()) {}

Blowfish::~Blowfish() {
    memset(&ctx, 0, sizeof(ctx));
}

SequentialData Blowfish::encrypt(const pgfe_encode_t *seq, size_t length) {
    size_t sz = length + length % 8;
    std::unique_ptr<pgfe_encode_t[]> output = std::make_unique<pgfe_encode_t[]>(sz);

    sz = pgfe_blowfish_encrypt(&ctx, seq, length, output.get());
    return SequentialData(output.get(), sz);
}

SequentialData Blowfish::decrypt(const pgfe_encode_t *seq, size_t length) {
    size_t sz = length + length % 8;
    std::unique_ptr<pgfe_encode_t[]> output = std::make_unique<pgfe_encode_t[]>(sz);

    sz = pgfe_blowfish_decrypt(&ctx, seq, length, output.get());
    return SequentialData(output.get(), sz);
}

SequentialData Blowfish::encrypt(const std::string &cpp_s) {
    return this->AbstractSymmetricCrypter::encrypt(cpp_s);
}

SequentialData Blowfish::encrypt(const char *cs) {
    return this->AbstractSymmetricCrypter::encrypt(cs);
}

SequentialData Blowfish::encrypt(const SequentialData &sd) {
    return this->AbstractSymmetricCrypter::encrypt(sd);
}

SequentialData Blowfish::decrypt(const std::string &cpp_s) {
    return this->AbstractSymmetricCrypter::decrypt(cpp_s);
}

SequentialData Blowfish::decrypt(const char *cs) {
    return this->AbstractSymmetricCrypter::decrypt(cs);
}

SequentialData Blowfish::decrypt(const SequentialData &sd) {
    return this->AbstractSymmetricCrypter::decrypt(sd);
}