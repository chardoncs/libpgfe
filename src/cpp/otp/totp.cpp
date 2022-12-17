/*
  libpgfe
  totp.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "totp.hpp"

#include "utils.h"

using namespace libpgfe;

void TOTP::set_interval(pgfe_totp_interval_t interval) {
    this->_interval = interval;
}

pgfe_totp_interval_t TOTP::interval() const {
    return _interval;
}

time_t TOTP::initial_time() const {
    return _initial_time;
}

void TOTP::set_initial_time(time_t _initial_time) {
    this->_initial_time = _initial_time;
}

time_t TOTP::update_time() const {
    return _update_time;
}

void TOTP::update_counter() {
    _update_time = pgfe_curtime();
    set_counter(__pgfe_calc_periodic_counter(_update_time, _interval, _initial_time, &delta));
}

time_t TOTP::remaining_time() const {
    return delta - (pgfe_curtime() - _update_time);
}

TOTP::TOTP(pgfe_totp_interval_t interval, pgfe_algorithm_choice algorithm) : HOTP(algorithm) {
    set_interval(interval);
}

TOTP::TOTP(
    const pgfe_encode_t *secret_seq, size_t length, pgfe_totp_interval_t interval, pgfe_algorithm_choice algorithm
)
    : HOTP(secret_seq, length, algorithm) {
    set_interval(interval);
}
TOTP::TOTP(const char *secret_cs, pgfe_totp_interval_t interval, pgfe_algorithm_choice algorithm)
    : HOTP(secret_cs, algorithm) {
    set_interval(interval);
}

TOTP::TOTP(std::string &secret_cpp_s, pgfe_totp_interval_t interval, pgfe_algorithm_choice algorithm)
    : HOTP(secret_cpp_s, algorithm) {
    set_interval(interval);
}

TOTP::TOTP(SequentialData &sd, pgfe_totp_interval_t interval, pgfe_algorithm_choice algorithm) : HOTP(sd, algorithm) {
    set_interval(interval);
}

TOTP::~TOTP() {}