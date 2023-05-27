/*
  libpgfe
  blowfish_test.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/libpgfe/blowfish.h"
#include "../include/libpgfe/utils.h"

void blowfish_encrypt_unit_test(ARGS) {
    struct pgfe_blowfish_ctx ctx;
    uint64_t input;

    sscanf(argv[3], "%lu", &input);
    pgfe_blowfish_init(&ctx, (const pgfe_encode_t *)argv[2], strlen(argv[2]));

    pgfe_blowfish_encrypt_unit(&ctx, (pgfe_fake_uint64_t *)&input);

    printf("%lX\n", input);
}

void blowfish_decrypt_unit_test(ARGS) {
    struct pgfe_blowfish_ctx ctx;
    uint64_t input;

    sscanf(argv[3], "%lx", &input);
    pgfe_blowfish_init(&ctx, (const pgfe_encode_t *)argv[2], strlen(argv[2]));

    pgfe_blowfish_decrypt_unit(&ctx, (pgfe_fake_uint64_t *)&input);

    printf("%lu\n", input);
}

void blowfish_encrypt_string_test(ARGS) {
    struct pgfe_blowfish_ctx ctx;
    pgfe_encode_t out[400];
    char out_hex[400];
    size_t out_size;

    pgfe_blowfish_init(&ctx, (const pgfe_encode_t *)argv[2], strlen(argv[2]));

    out_size = pgfe_blowfish_encrypt(&ctx, (const pgfe_encode_t *)argv[3], strlen(argv[3]), out);

    pgfe_hash_to_hex_string(out, out_size, out_hex);
    puts(out_hex);
}

void blowfish_decrypt_string_test(ARGS) {
    struct pgfe_blowfish_ctx ctx;
    pgfe_encode_t input[400], out[400];
    size_t input_size;

    input_size = pgfe_hex_string_to_hash(argv[3], input);

    pgfe_blowfish_init(&ctx, (const pgfe_encode_t *)argv[2], strlen(argv[2]));

    pgfe_blowfish_decrypt(&ctx, input, input_size, out);

    puts((const char *)out);
}