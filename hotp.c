#include "hotp.h"

#include <string.h>

#include "sha1.h"

pgfe_otp_t __pgfe_10pow(uint8_t p) {
    pgfe_otp_t r = 1;
    for (; p > 0; p--) {
        r *= 10;
    }
    return r;
}

pgfe_otp_t pgfe_hotp_generic(
    pgfe_encode_multi_func *func, size_t block_size, size_t digest_size, const pgfe_encode_t secret[],
    pgfe_otp_counter_t counter, uint8_t digit_c
) {
    size_t sec_len = strlen((char *)secret);
    size_t counter_len = sizeof(pgfe_otp_counter_t) / sizeof(pgfe_encode_t);
    pgfe_encode_t counter_h[counter_len];
    pgfe_encode_t out_hash[digest_size];
    pgfe_otp_t result;

    memcpy(counter_h, &counter, counter_len);

    pgfe_hmac_generic(func, block_size, digest_size, secret, sec_len, counter_h, counter_len, out_hash, digest_size);
    result = pgfe_dynamically_truncate(out_hash, digest_size);

    if (digit_c < PGFE_OTP_DIGIT_MAX_LIMIT) {
        result %= __pgfe_10pow(digit_c);
    }

    return result;
}

inline pgfe_otp_t pgfe_hotp(const pgfe_encode_t secret[], pgfe_otp_counter_t counter, uint8_t digit_c) {
    return pgfe_hotp_generic(
        pgfe_sha1_encode_multiple, PGFE_SHA1_BLOCK_SIZE, PGFE_SHA1_DIGEST_SIZE, secret, counter, digit_c
    );
}

inline pgfe_otp_t pgfe_hotp_4digits(const pgfe_encode_t secret[], pgfe_otp_counter_t counter) {
    return pgfe_hotp(secret, counter, 4);
}

inline pgfe_otp_t pgfe_hotp_6digits(const pgfe_encode_t secret[], pgfe_otp_counter_t counter) {
    return pgfe_hotp(secret, counter, 6);
}

inline pgfe_otp_t pgfe_hotp_8digits(const pgfe_encode_t secret[], pgfe_otp_counter_t counter) {
    return pgfe_hotp(secret, counter, 8);
}