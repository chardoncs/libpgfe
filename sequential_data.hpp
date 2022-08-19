#ifndef LIBPGFE_SEQUENTIAL_DATA_HPP
#define LIBPGFE_SEQUENTIAL_DATA_HPP
#ifdef __cplusplus

#include <string>

#include "generic.h"

namespace chardon55 {
namespace PGFE {

class SequentialData
{
  private:
    pgfe_encode_t *seq = nullptr;
    size_t sz = 0, hex_sz = 0;

    char *hex_str = nullptr;

  public:
    SequentialData(const pgfe_encode_t *, size_t);
    SequentialData(const char *);
    SequentialData(const std::string &);
    ~SequentialData();

    const char *to_cs();
    std::string to_str();

    const char *to_hex_cs();
    std::string to_hex_str();

    const pgfe_encode_t *to_pgfe_seq();
    const pgfe_encode_t *to_pgfe_seq(size_t &);

    size_t length();
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif