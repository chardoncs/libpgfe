#include "test.h"

#include "../hmac_encoder.hpp"
#include "../utils.h"

using namespace chardon55::PGFE;

void hmacencodertest(ARGS) {
    HMACEncoder encoder;

    if (argc >= 3) {
        encoder.set_key(argv[2]);
    }
    if (argc >= 4) {
        encoder.update(argv[3]);
    }

    auto sd = encoder.get_digest();
    puts(sd.to_hex_cs());
}