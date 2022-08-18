#ifndef LIBPGFE_HMAC_ENCODER_HPP
#define LIBPGFE_HMAC_ENCODER_HPP
#ifdef __cplusplus

#include "generic.h"
#include "generic.hpp"
#include "generic_hash_encoder.hpp"

namespace chardon55 {
namespace PGFE {

class HMACEncoder : public GenericHashEncoder
{
  private:
    pgfe_algorithm_choice choice;

    pgfe_encode_multi_func *encode_func;

    pgfe_encode_t *key, *data;
    size_t key_len, data_len;

    void destroy_key();
    void destroy_data();

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

    void select_algorithm(pgfe_algorithm_choice);
    void select_algorithm(const std::string &);
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif