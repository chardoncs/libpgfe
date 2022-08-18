add_test(
    NAME hash_encoder_SHA1
    COMMAND pgfetestcpp hash_encoder sha1 ${test_text}
)

add_test(
    NAME hash_encoder_SHA224
    COMMAND pgfetestcpp hash_encoder sha224 ${test_text}
)
add_test(
    NAME hash_encoder_SHA256
    COMMAND pgfetestcpp hash_encoder sha256 ${test_text}
)
add_test(
    NAME hash_encoder_SHA384
    COMMAND pgfetestcpp hash_encoder sha384 ${test_text}
)
add_test(
    NAME hash_encoder_SHA512
    COMMAND pgfetestcpp hash_encoder sha512 ${test_text}
)
add_test(
    NAME hash_encoder_SHA3_224
    COMMAND pgfetestcpp hash_encoder sha3_224 ${test_text}
)
add_test(
    NAME hash_encoder_SHA3_256
    COMMAND pgfetestcpp hash_encoder sha3_256 ${test_text}
)
add_test(
    NAME hash_encoder_SHA3_384
    COMMAND pgfetestcpp hash_encoder sha3_384 ${test_text}
)
add_test(
    NAME hash_encoder_SHA3_512
    COMMAND pgfetestcpp hash_encoder sha3_512 ${test_text}
)

set_property(TEST hash_encoder_SHA1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST hash_encoder_SHA224 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha224})
set_property(TEST hash_encoder_SHA256 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha256})
set_property(TEST hash_encoder_SHA384 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha384})
set_property(TEST hash_encoder_SHA512 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha512})
set_property(TEST hash_encoder_SHA3_224 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_224})
set_property(TEST hash_encoder_SHA3_256 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_256})
set_property(TEST hash_encoder_SHA3_384 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_384})
set_property(TEST hash_encoder_SHA3_512 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_512})