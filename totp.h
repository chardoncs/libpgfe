#ifndef LIBPGFE_TOTP_H
#define LIBPGFE_TOTP_H

#include "otp-generic.h"

#ifdef __cplusplus
extern "C" {
#endif

// Get current UNIX time as counters' type
pgfe_otp_counter_t pgfe_current_unix_time();

// Generic HOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_totp_generic(
    pgfe_encode_multi_func *func, size_t block_size, size_t digest_size, const pgfe_encode_t secret[], uint8_t digit_c
);

// Common HOTP using HMAC-SHA1 algorithm
pgfe_otp_t pgfe_totp(const pgfe_encode_t secret[], uint8_t digit_c);

pgfe_otp_t pgfe_totp_4digits(const pgfe_encode_t secret[]);

pgfe_otp_t pgfe_totp_6digits(const pgfe_encode_t secret[]);

pgfe_otp_t pgfe_totp_8digits(const pgfe_encode_t secret[]);

#ifdef __cplusplus
}
#endif

#endif