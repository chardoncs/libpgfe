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

#include "libpgfe/generic.h"
#include "libpgfe/utils.h"

namespace libpgfe {

typedef std::basic_string<pgfe_encode_t> pgfe_seqdata_t;

class SequentialData : public pgfe_seqdata_t
{
private:
    const pgfe_encode_t ws[1] = {0};

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

    SequentialData trim();
    SequentialData trim_left();
    SequentialData trim_right();

    void trim_();
    void trim_left_();
    void trim_right_();

    inline friend std::ostream &operator<<(std::ostream &os, const SequentialData &sd) {
        os << sd.to_str();
        return os;
    }
};

} // namespace libpgfe

#endif