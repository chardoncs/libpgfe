#include "hash_encoder.hpp"

#include <cstring>
#include <stdexcept>

#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"

#include "utils.h"

#define __PGFE_CTX_CREATE_CASE(alg, name)                                                                              \
    case alg:                                                                                                          \
        this->ctx = (void *)new name##_ctx;                                                                            \
        break

#define __PGFE_CTX_DELETE_CASE(alg, name)                                                                              \
    case alg:                                                                                                          \
        delete (name##_ctx *)ctx;                                                                                      \
        break

#define __PGFE_INIT_FUNC_CALL_CASE(alg, name)                                                                          \
    case alg:                                                                                                          \
        name##_init((name##_ctx *)ctx);                                                                                \
        break

#define __PGFE_UPDATE_FUNC_CALL1_CASE(alg, name)                                                                       \
    case alg:                                                                                                          \
        name##_update((name##_ctx *)ctx, strlen(cs), (uint8_t *)cs);                                                   \
        break

#define __PGFE_UPDATE_FUNC_CALL2_CASE(alg, name)                                                                       \
    case alg:                                                                                                          \
        name##_update((name##_ctx *)ctx, cpp_s.length(), (uint8_t *)cpp_s.c_str());                                    \
        break

#define __PGFE_UPDATE_FUNC_CALL3_CASE(alg, name)                                                                       \
    case alg:                                                                                                          \
        name##_update((name##_ctx *)ctx, length, sequence);                                                            \
        break

#define __PGFE_DIGEST_FUNC_CALL_CASE(alg, name)                                                                        \
    case alg:                                                                                                          \
        name##_digest((name##_ctx *)ctx, length ? length : pgfe_digest_length[cur], out);                              \
        break

#define __PGFE_INIT_SIZE_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        digsz = PGFE_##alg##_DIGEST_SIZE;                                                                              \
        blocksz = PGFE_##alg##_BLOCK_SIZE;                                                                             \
        break

using namespace chardon55::PGFE;

void HashEncoder::destroy_context() {
    if (!ctx) return;

    __PGFE_BATCH_CASES(CTX_DELETE)
}

void HashEncoder::select_algorithm(pgfe_algorithm_choice choice) {
    if (choice == cur) return;

    destroy_context();
    cur = choice;
    load_algorithm();
}

void HashEncoder::select_algorithm(const std::string &s) {
    this->GenericHashEncoder::select_algorithm(s);
}

void HashEncoder::load_algorithm() {
    __PGFE_BATCH_CASES(CTX_CREATE)
    __PGFE_BATCH_CASES(INIT_FUNC_CALL)
    __PGFE_BATCH_CASES(INIT_SIZE)
}

void HashEncoder::reset() {
    destroy_context();
    load_algorithm();
}

void HashEncoder::init() {
    reset();
}

HashEncoder::HashEncoder(pgfe_algorithm_choice choice) {
    select_algorithm(choice);
    init();
}

HashEncoder::HashEncoder(const std::string &choice) {
    select_algorithm(choice);
    init();
}

HashEncoder::~HashEncoder() {
    destroy_context();
}

void HashEncoder::update(const pgfe_encode_t sequence[], size_t length) {
    __PGFE_BATCH_CASES(UPDATE_FUNC_CALL3)
}

void HashEncoder::update(const char cs[]) {
    __PGFE_BATCH_CASES(UPDATE_FUNC_CALL1)
}

void HashEncoder::update(const std::string &cpp_s) {
    __PGFE_BATCH_CASES(UPDATE_FUNC_CALL2)
}

void HashEncoder::get_digest(pgfe_encode_t out[], size_t length) {
    __PGFE_BATCH_CASES(DIGEST_FUNC_CALL)
}