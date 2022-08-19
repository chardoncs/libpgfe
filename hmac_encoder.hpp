#ifndef LIBPGFE_HMAC_ENCODER_HPP
#define LIBPGFE_HMAC_ENCODER_HPP
#ifdef __cplusplus

#include "abstract_hash_encoder.hpp"
#include "generic.h"
#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

class HMACEncoder : public AbstractHashEncoder
{
  private:
    pgfe_encode_multi_func *encode_func;

    pgfe_encode_t *key, *data;
    size_t key_len, data_len;

    void destroy_key();
    void destroy_data();

  protected:
    void after_change_alg();

  public:
    HMACEncoder();
    ~HMACEncoder();

    void set_key(const pgfe_encode_t sequence[], size_t length);
    void set_key(const char cs[]);
    void set_key(const std::string &cpp_s);

    void update(const pgfe_encode_t sequence[], size_t length);
    void update(const char cs[]);
    void update(const std::string &cpp_s);

    void get_digest(pgfe_encode_t out[], size_t length);
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif