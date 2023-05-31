/*
  libpgfe
  blowfish.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_BLOWFISH_HPP
#define LIBPGFE_BLOWFISH_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "libpgfe/abstract_symmetric_crypter.hpp"
#include "libpgfe/fishes/blowfish.h"

namespace libpgfe {

class Blowfish : public AbstractSymmetricCrypter
{
private:
    pgfe_blowfish_ctx ctx;

public:
    Blowfish(const SequentialData &key);
    Blowfish(const char key[]);
    Blowfish(const pgfe_encode_t *key, size_t length);
    Blowfish(const std::string &key);
    ~Blowfish();

    SequentialData encrypt(const std::string &);
    SequentialData encrypt(const char *);
    SequentialData encrypt(const SequentialData &);
    SequentialData encrypt(const pgfe_encode_t *, size_t);

    SequentialData decrypt(const std::string &);
    SequentialData decrypt(const char *);
    SequentialData decrypt(const SequentialData &);
    SequentialData decrypt(const pgfe_encode_t *, size_t);
};

} // namespace libpgfe

#endif