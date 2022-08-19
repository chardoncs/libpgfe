/*
  libpgfe
  totp.cpp

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#include "totp.hpp"

#include "utils.h"

using namespace chardon55::PGFE;

void TOTP::set_interval(pgfe_totp_interval_t interval) {
    this->interval = interval;
}

pgfe_totp_interval_t TOTP::get_interval() {
    return interval;
}

pgfe_time_t TOTP::get_initial_time() {
    return initial_time;
}

void TOTP::set_initial_time(pgfe_time_t initial_time) {
    this->initial_time = initial_time;
}

pgfe_time_t TOTP::get_update_time() {
    return update_time;
}

void TOTP::update_counter() {
    update_time = pgfe_curtime();
    set_counter(__pgfe_calc_periodic_counter(update_time, interval, initial_time, &delta));
}

pgfe_time_t TOTP::get_remain_time() {
    return delta - (pgfe_curtime() - update_time);
}

TOTP::TOTP(pgfe_totp_interval_t interval) {
    set_interval(interval);
}

TOTP::TOTP(const pgfe_encode_t *secret_seq, size_t length, pgfe_totp_interval_t interval) : HOTP(secret_seq, length) {
    set_interval(interval);
}
TOTP::TOTP(const char *secret_cs, pgfe_totp_interval_t interval) : HOTP(secret_cs) {
    set_interval(interval);
}

TOTP::TOTP(std::string &secret_cpp_s, pgfe_totp_interval_t interval) : HOTP(secret_cpp_s) {
    set_interval(interval);
}

TOTP::TOTP(SequentialData &sd, pgfe_totp_interval_t interval) : HOTP(sd) {
    set_interval(interval);
}

TOTP::~TOTP() {}