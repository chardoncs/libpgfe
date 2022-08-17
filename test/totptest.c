#include <stdio.h>

#include "../totp.h"

int main(int argc, char **argv) {
    char secret[] = "OTDOCKWULVEFCPIX";

    pgfe_otp_t code = pgfe_totp_6digits((pgfe_encode_t *)secret);
    printf("%u\n", code);
}