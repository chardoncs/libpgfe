/*
  libpgfe
  abstract_symmetric_crypter.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "backend_cpp/abstract_symmetric_crypter.hpp"

using namespace libpgfe;

SequentialData AbstractSymmetricCrypter::encrypt(const std::string &cpp_s) {
    return encrypt((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

SequentialData AbstractSymmetricCrypter::encrypt(const char *cs) {
    return encrypt((const pgfe_encode_t *)cs, strlen(cs));
}

SequentialData AbstractSymmetricCrypter::encrypt(const SequentialData &sd) {
    return encrypt(sd.to_pgfe_seq(), sd.length());
}

SequentialData AbstractSymmetricCrypter::decrypt(const std::string &cpp_s) {
    return decrypt((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

SequentialData AbstractSymmetricCrypter::decrypt(const char *cs) {
    return decrypt((const pgfe_encode_t *)cs, strlen(cs));
}

SequentialData AbstractSymmetricCrypter::decrypt(const SequentialData &sd) {
    return decrypt(sd.to_pgfe_seq(), sd.length());
}
