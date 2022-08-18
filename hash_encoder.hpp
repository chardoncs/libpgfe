#ifndef LIBPGFE_HASH_ENCODER_HPP
#define LIBPGFE_HASH_ENCODER_HPP
#ifdef __cplusplus
#include "generic_hash_encoder.hpp"

#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

// Libpgfe - Hash Encoder
class HashEncoder : public GenericHashEncoder
{

  private:
    void *ctx = nullptr;

    size_t digsz, blocksz;

    void load_algorithm();

    void destroy_context();

    void init();

  public:
    HashEncoder(pgfe_algorithm_choice choice = SHA1);
    HashEncoder(const std::string &choice);
    ~HashEncoder();

    void reset();

    void update(const pgfe_encode_t sequence[], size_t length);
    void update(const char cs[]);
    void update(const std::string &cpp_s);

    void get_digest(pgfe_encode_t out[], size_t length);

    void select_algorithm(pgfe_algorithm_choice);
    void select_algorithm(const std::string &);

    size_t digest_size() {
        return digsz;
    }

    size_t block_size() {
        return blocksz;
    }
};

} // namespace PGFE
} // namespace chardon55
#endif
#endif