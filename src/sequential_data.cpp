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

size_t SequentialData::length() {
    return sz;
}

const char *SequentialData::to_cs() {
    return (const char *)seq;
}

std::string SequentialData::to_str() {
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

std::string SequentialData::to_hex_str() {
    std::string s(to_hex_cs());
    return s;
}

const pgfe_encode_t *SequentialData::to_pgfe_seq() {
    return seq;
}

const pgfe_encode_t *SequentialData::to_pgfe_seq(size_t &length_out) {
    length_out = sz;
    return to_pgfe_seq();
}

bool SequentialData::is_str() {
    return _is_str;
}

void SequentialData::set_is_str(bool str) {
    _is_str = str;
}

bool SequentialData::is_apparent_str() {
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

SequentialData *SequentialData::truncate(size_t start, size_t length, bool inplace) {
    if (inplace) {
        if (start) {
            memcpy(seq, seq + start, length);
        }

        memset(seq + length, 0, sz - length);
        sz = length;
        return nullptr;
    }

    return new SequentialData(&seq[start], length);
}

SequentialData *SequentialData::copy() {
    return new SequentialData((const pgfe_encode_t *)seq, sz);
}