#include <stdio.h>
#include <string.h>

#include "../hotp.h"
#include "../totp.h"
#include "../utils.h"

int main(int argc, char **argv) {
    char secret[] = "OTDOCKWULVEFCPIX";
    // char secret2[] = "3132333435363738393031323334353637383930";

    // pgfe_encode_t key[100];
    // pgfe_hex_string_to_hash(secret2, key);
    // pgfe_otp_t o = pgfe_hotp_8digits(key, 20, 1);
    // printf("%d\n", o);

    int delta;

    pgfe_otp_t code = pgfe_totp_6digits((pgfe_encode_t *)secret, strlen(secret), 30, &delta);
    printf("%u\n", code);
    printf("%d\n", delta);
}