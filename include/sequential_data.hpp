/*
  libpgfe
  sequential_data.hpp

  Header of Sequential Data class

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_SEQUENTIAL_DATA_HPP
#define LIBPGFE_SEQUENTIAL_DATA_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <ostream>
#include <string>

#include "generic.h"
#include "utils.h"

namespace chardon55 {
namespace PGFE {

typedef std::basic_string<pgfe_encode_t> pgfe_seqdata_t;

class SequentialData : public pgfe_seqdata_t
{
private:
    bool _is_str = false, _str_deter_overwrite = false;

    bool determine_ascii_str() const;

public:
    SequentialData();
    SequentialData(const SequentialData *);
    SequentialData(const SequentialData &);
    SequentialData(SequentialData &&);
    SequentialData(const pgfe_encode_t[], size_t size);
    SequentialData(const char[]);
    SequentialData(const std::string);

    std::string to_str(bool auto_hex = true) const;

    std::string hex_str() const;

    const pgfe_encode_t *to_pgfe_seq() const;
    const pgfe_encode_t *to_pgfe_seq(size_t &) const;

    bool is_str() const;
    void set_is_str(bool);

    bool is_apparent_str() const;

    inline friend std::ostream &operator<<(std::ostream &os, const SequentialData &sd) {
        os << sd.to_str();
        return os;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif