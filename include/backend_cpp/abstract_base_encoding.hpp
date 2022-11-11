/*
  libpgfe
  abstract_base_encoding.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_ABSTRACT_BASE_ENCODING
#define LIBPGFE_ABSTRACT_BASE_ENCODING
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <memory>
#include <mutex>
#include <string>

#include "../generic.h"
#include "../sequential_data.hpp"

namespace chardon55 {
namespace PGFE {

typedef size_t base_encode_func(const pgfe_encode_t *, size_t, char *);
typedef size_t base_decode_func(const char *, pgfe_encode_t *);

typedef unsigned short base_short_size_t;

class AbstractBaseEncoding
{
private:
    std::unique_ptr<pgfe_encode_t[]> de_cache = std::make_unique<pgfe_encode_t[]>(64);
    std::unique_ptr<char[]> en_cache = std::make_unique<char[]>(128);
    size_t encsz = 127, decsz = 64;

    std::mutex enc_mutex, dec_mutex;

    base_short_size_t unitsz, chunksz, bitsz, alphabetsz;

protected:
    base_encode_func *encode_f;
    base_decode_func *decode_f;

    virtual void init_base_function(base_encode_func *&encode_f_ref, base_decode_func *&decode_f_ref) {}

    virtual void init_size(
        base_short_size_t &unitsz, base_short_size_t &chunksz, base_short_size_t &bitsz, base_short_size_t &alphabetsz
    ) {}

    void init();

public:
    std::string encode(const pgfe_encode_t *, size_t);
    std::string encode(const char *);
    std::string encode(std::string &);
    std::string encode(SequentialData &);

    SequentialData decode(const char *);
    SequentialData decode(std::string &);

    base_short_size_t unit_size() const;
    base_short_size_t chunk_size() const;
    base_short_size_t bit_size() const;
    base_short_size_t alphabet_size() const;
};

} // namespace PGFE
} // namespace chardon55

#endif