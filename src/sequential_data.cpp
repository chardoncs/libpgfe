/*
  libpgfe
  sequential_data.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "sequential_data.hpp"

#include <cstring>

using namespace chardon55::PGFE;

SequentialData::~SequentialData() {
    if (seq) {
        delete[] seq;
    }

    if (hex_str) {
        delete[] hex_str;
    }
}

SequentialData::SequentialData(const pgfe_encode_t *pgfe_seq, size_t length) {
    seq = new pgfe_encode_t[length + 1];
    memcpy(seq, pgfe_seq, length);
    seq[length] = 0;
    sz = length;
    _is_str = _apstr = determine_ascii_str();
}

SequentialData::SequentialData(const char *cs) : SequentialData((const pgfe_encode_t *)cs, strlen(cs)) {}

SequentialData::SequentialData(std::string &cpp_s)
    : SequentialData((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length()) {}

SequentialData::SequentialData(const SequentialData *sd) : SequentialData((const pgfe_encode_t *)sd->seq, sd->sz) {}

SequentialData::SequentialData(SequentialData *sd, bool delete_current)
    : SequentialData((const pgfe_encode_t *)sd->seq, sd->sz) {
    if (delete_current) {
        delete sd;
    }
}

size_t SequentialData::length() const {
    return sz;
}

const char *SequentialData::to_cs() const {
    return (const char *)seq;
}

std::string SequentialData::to_str() const {
    std::string s((char *)seq);
    return s;
}

const char *SequentialData::to_hex_cs() {
    if (!hex_str) {
        hex_sz = sz * 2;
        hex_str = new char[hex_sz + 1];
    }

    pgfe_hash_to_hex_string(seq, sz, hex_str);
    return hex_str;
}

std::string SequentialData::to_hex_str() const {
    char hex_str[sz * 2 + 1];
    pgfe_hash_to_hex_string(seq, sz, hex_str);
    std::string s(hex_str);
    return s;
}

const pgfe_encode_t *SequentialData::to_pgfe_seq() const {
    return seq;
}

const pgfe_encode_t *SequentialData::to_pgfe_seq(size_t &length_out) const {
    length_out = sz;
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

bool SequentialData::determine_ascii_str() {
    for (size_t i = 0; i < sz; i++) {
        if (seq[i] > 0x7F || seq[i] < 0x20) {
            return false;
        }
    }

    return true;
}

SequentialData *SequentialData::truncate(size_t start, size_t length) const {
    return new SequentialData(&seq[start], length);
}

SequentialData *SequentialData::truncate(size_t start, size_t length, bool inplace) {
    if (inplace) {
        if (start) {
            memcpy(seq, seq + start, length);
        }

        memset(seq + length, 0, sz - length);
        sz = length;
        return nullptr;
    }

    return truncate(start, length);
}

SequentialData *SequentialData::copy() const {
    return new SequentialData((const pgfe_encode_t *)seq, sz);
}