/*
  libpgfe
  sequential_data.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "sequential_data.hpp"

#include <cstring>
#include <stdexcept>

using namespace chardon55::PGFE;

SequentialData::SequentialData() : pgfe_seqdata_t() {
    determine_ascii_str();
}

SequentialData::SequentialData(const SequentialData &sd) : pgfe_seqdata_t(sd) {
    determine_ascii_str();
}

SequentialData::SequentialData(const SequentialData *sdp) : pgfe_seqdata_t(*sdp) {
    determine_ascii_str();
}

SequentialData::SequentialData(SequentialData &&sd) : pgfe_seqdata_t(sd) {
    determine_ascii_str();
}

SequentialData::SequentialData(const pgfe_encode_t pgfe_seq[], size_t size) : pgfe_seqdata_t(pgfe_seq, size) {
    determine_ascii_str();
}

SequentialData::SequentialData(const char c_str[]) : SequentialData((const pgfe_encode_t *)c_str, strlen(c_str)) {}
SequentialData::SequentialData(const std::string cpp_str)
    : SequentialData((const pgfe_encode_t *)cpp_str.c_str(), cpp_str.length()) {}

std::string SequentialData::to_str(bool auto_hex) const {
    if (!_is_str && auto_hex) {
        return hex_str();
    }

    std::string s((const char *)this->c_str(), this->length());
    return s;
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

bool SequentialData::is_str() const {
    return _is_str;
}

void SequentialData::set_is_str(bool str) {
    _is_str = str;
}

bool SequentialData::is_apparent_str() const {
    return _apstr;
}

void SequentialData::determine_ascii_str() {
    pgfe_encode_t ch;
    for (const_iterator iter = begin(); iter != end(); iter++) {
        ch = *iter;
        _is_str = ch >= 0x20 && ch <= 0x7F;
        if (!_is_str) {
            return;
        }
    }
}
