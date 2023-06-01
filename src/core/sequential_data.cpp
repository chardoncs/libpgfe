/*
  libpgfe
  sequential_data.cpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/sequential_data.hpp"

#include <cstring>
#include <stdexcept>

using namespace libpgfe;

SequentialData::SequentialData() : pgfe_seqdata_t() {}

SequentialData::SequentialData(const SequentialData &sd) : pgfe_seqdata_t(sd) {}

SequentialData::SequentialData(const SequentialData *sdp) : pgfe_seqdata_t(*sdp) {}

SequentialData::SequentialData(SequentialData &&sd) : pgfe_seqdata_t(sd) {}

SequentialData::SequentialData(const pgfe_encode_t pgfe_seq[], size_t size) : pgfe_seqdata_t(pgfe_seq, size) {}

SequentialData::SequentialData(const char c_str[]) : SequentialData((const pgfe_encode_t *)c_str, strlen(c_str)) {}

SequentialData::SequentialData(const std::string cpp_str)
    : SequentialData((const pgfe_encode_t *)cpp_str.c_str(), cpp_str.length()) {}

std::string SequentialData::to_str(bool auto_hex) const {
    return std::string((const char *)this->c_str(), this->length());
}

std::string SequentialData::hex_str() const {
    size_t sz = this->length();
    char hex_str[sz * 2 + 1];
    pgfe_hash_to_hex_string(this->c_str(), sz, hex_str);
    std::string s(hex_str);
    return s;
}

const pgfe_encode_t *SequentialData::to_pgfe_seq() const {
    return this->c_str();
}

const pgfe_encode_t *SequentialData::to_pgfe_seq(size_t &length_out) const {
    length_out = this->length();
    return to_pgfe_seq();
}

SequentialData SequentialData::trim() {
    auto sd = SequentialData(this);
    sd.trim_();
    return sd;
}

SequentialData SequentialData::trim_left() {
    auto sd = SequentialData(this);
    sd.trim_left_();
    return sd;
}

SequentialData SequentialData::trim_right() {
    auto sd = SequentialData(this);
    sd.trim_right_();
    return sd;
}

inline void SequentialData::trim_() {
    trim_left_();
    trim_right_();
}

inline void SequentialData::trim_left_() {
    erase(0, find_first_not_of(ws));
}

inline void SequentialData::trim_right_() {
    erase(find_last_not_of(ws) + 1, length());
}