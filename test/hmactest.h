/*
  libpgfe
  hmactest.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/hmac.h"
#include "../include/md5.h"
#include "../include/utils.h"

enum pgfe_algorithm_choice get_alg_choice(char option[]) {
    enum pgfe_algorithm_choice c;

    if (!strcmp(option, "md5")) {
        c = MD5;
    }
    else if (!strcmp(option, "sha1")) {
        c = SHA1;
    }
    else if (!strcmp(option, "sha224")) {
        c = SHA224;
    }
    else if (!strcmp(option, "sha256")) {
        c = SHA256;
    }
    else if (!strcmp(option, "sha384")) {
        c = SHA384;
    }
    else if (!strcmp(option, "sha512")) {
        c = SHA512;
    }
    else {
        c = MD5;
    }

    return c;
}

uint16_t get_alg_digest_size(char option[]) {
    uint16_t c;

    if (!strcmp(option, "md5")) {
        c = PGFE_MD5_DIGEST_SIZE;
    }
    else if (!strcmp(option, "sha1")) {
        c = PGFE_SHA1_DIGEST_SIZE;
    }
    else if (!strcmp(option, "sha224")) {
        c = PGFE_SHA224_DIGEST_SIZE;
    }
    else if (!strcmp(option, "sha256")) {
        c = PGFE_SHA256_DIGEST_SIZE;
    }
    else if (!strcmp(option, "sha384")) {
        c = PGFE_SHA384_DIGEST_SIZE;
    }
    else if (!strcmp(option, "sha512")) {
        c = PGFE_SHA512_DIGEST_SIZE;
    }
    else {
        c = PGFE_SHA512_DIGEST_SIZE;
    }

    return c;
}

void hmac_test(ARGS) {
    char *raw_key = argv[3], *data = argv[4];
    uint16_t size = get_alg_digest_size(argv[2]);
    pgfe_encode_t key[256], out[size];
    size_t key_len;

    if (raw_key[0] == '0' && raw_key[1] == 'x') {
        pgfe_hex_string_to_hash(raw_key, key);
        key_len = pgfe_hash_length(raw_key);
    }
    else {
        key_len = strlen(raw_key);
        memcpy(key, raw_key, key_len);
    }

    // pgfe_hmac(get_alg_choice(argv[2]), key, key_len, (const pgfe_encode_t *)data, strlen(data), out);
    struct pgfe_hmac_sha256_ctx ctx;
    pgfe_hmac_sha256_init(&ctx);
    pgfe_hmac_sha256_set_key(&ctx, key, key_len);
    pgfe_hmac_sha256_update(&ctx, (const pgfe_encode_t *)data, strlen(data));
    pgfe_hmac_sha256_digest(&ctx, out);

    pgfe_print_hash(out, size);
}
