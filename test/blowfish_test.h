#include "test.h"

#include "../include/blowfish.h"

void blowfish_encrypt_unit_test(ARGS) {
    struct pgfe_blowfish_ctx ctx;
    uint64_t input;

    sscanf(argv[3], "%lu", &input);
    pgfe_blowfish_init(&ctx, (pgfe_encode_t *)argv[2], strlen(argv[2]));

    pgfe_blowfish_encrypt_unit(&ctx, (pgfe_fake_uint64_t *)&input);

    printf("%lX\n", input);
}

void blowfish_decrypt_unit_test(ARGS) {
    struct pgfe_blowfish_ctx ctx;
    uint64_t input;

    sscanf(argv[3], "%lx", &input);
    pgfe_blowfish_init(&ctx, (pgfe_encode_t *)argv[2], strlen(argv[2]));

    pgfe_blowfish_decrypt_unit(&ctx, (pgfe_fake_uint64_t *)&input);

    printf("%lu\n", input);
}