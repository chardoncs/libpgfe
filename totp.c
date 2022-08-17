#include "totp.h"

#include "hotp.h"
#include "sha1.h"
#include "utils.h"

inline pgfe_otp_counter_t pgfe_current_unix_time() {
    return (pgfe_otp_counter_t)pgfe_curtime();
}

// Generic HOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_totp_generic(
    pgfe_encode_multi_func *func, size_t block_size, size_t digest_size, const pgfe_encode_t secret[], uint8_t digit_c
) {
    return pgfe_hotp_generic(func, block_size, digest_size, secret, pgfe_current_unix_time(), digit_c);
}

// Common HOTP using HMAC-SHA1 algorithm
inline pgfe_otp_t pgfe_totp(const pgfe_encode_t secret[], uint8_t digit_c) {
    return pgfe_totp_generic(pgfe_sha1_encode_multiple, PGFE_SHA1_BLOCK_SIZE, PGFE_SHA1_DIGEST_SIZE, secret, digit_c);
}

inline pgfe_otp_t pgfe_totp_4digits(const pgfe_encode_t secret[]) {
    return pgfe_totp(secret, 4);
}

inline pgfe_otp_t pgfe_totp_6digits(const pgfe_encode_t secret[]) {
    return pgfe_totp(secret, 6);
}

inline pgfe_otp_t pgfe_totp_8digits(const pgfe_encode_t secret[]) {
    return pgfe_totp(secret, 8);
}