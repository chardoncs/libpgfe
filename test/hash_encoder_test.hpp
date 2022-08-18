#include "test.h"

#include <string>

#include "../hash_encoder.hpp"
#include "../utils.h"

using namespace std;
using namespace chardon55::PGFE;

void hash_encoder_test(ARGS) {
    string option(argv[2]);
    HashEncoder encoder(option);

    size_t dsz = encoder.digest_size();

    pgfe_encode_t out[dsz];

    encoder.update(argv[3]);
    encoder.get_digest(out, dsz);

    pgfe_print_hash(out, dsz);
}