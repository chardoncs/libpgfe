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

typedef pgfe_encode_t seqdata_t;

class SequentialData
{
private:
    seqdata_t *seq = nullptr;
    size_t sz = 0, hex_sz = 0;

    char *hex_str = nullptr;

    bool _is_str, _apstr;

    bool determine_ascii_str();

public:
    SequentialData(const pgfe_encode_t *, size_t);
    SequentialData(const char *);
    SequentialData(std::string &);
    SequentialData(const SequentialData *);
    SequentialData(SequentialData *, bool delete_current);
    ~SequentialData();

    const char *to_cs() const;
    std::string to_str() const;

    const char *to_hex_cs();
    std::string to_hex_str() const;

    const pgfe_encode_t *to_pgfe_seq() const;
    const pgfe_encode_t *to_pgfe_seq(size_t &) const;

    size_t length() const;

    bool is_str() const;
    void set_is_str(bool);

    bool is_apparent_str() const;

    SequentialData *truncate(size_t start, size_t length, bool inplace);
    SequentialData *truncate(size_t start, size_t length) const;

    SequentialData *copy() const;

    friend std::ostream &operator<<(std::ostream &os, const SequentialData &sd) {
        if (sd._is_str) {
            os << (char *)sd.seq;
        }
        else {
            if (!sd.hex_str) {
                size_t hex_size = sd.sz * 2;
                char *hex_s = new char[hex_size + 1];
                size_t length = pgfe_hash_to_hex_string(sd.seq, sd.sz, hex_s);
                hex_s[length] = 0;
                for (int i = 0; i < length; i++) {
                    os << hex_s[i];
                }
                delete[] hex_s;
            }
            else {
                os << sd.hex_str;
            }
        }
        return os;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif