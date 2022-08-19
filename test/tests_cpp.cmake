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

add_test(
    NAME hmac_encoder_md5_1
    COMMAND pgfetestcpp hmac_encoder_hex "md5" "0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b" "Hi There"
)
add_test(
    NAME hmac_encoder_md5_2
    COMMAND pgfetestcpp hmac_encoder "md5" "Jefe" "what do ya want for nothing?"
)
add_test(
    NAME hmac_encoder_exception
    COMMAND pgfetestcpp hmac_encoder "md5" "Jefe" 
)

add_test(
    NAME hotp_sha1
    COMMAND pgfetestcpp hotp_hex sha1 "3132333435363738393031323334353637383930"
)
add_test(
    NAME hotp_sha256
    COMMAND pgfetestcpp hotp_hex sha256 "3132333435363738393031323334353637383930313233343536373839303132"
)
add_test(
    NAME hotp_sha512
    COMMAND pgfetestcpp hotp_hex sha512 "31323334353637383930313233343536373839303132333435363738393031323334353637383930313233343536373839303132333435363738393031323334"
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

set_property(TEST hmac_encoder_md5_1 PROPERTY PASS_REGULAR_EXPRESSION "9294727a3638bb1c13f48ef8158bfc9d")
set_property(TEST hmac_encoder_md5_2 PROPERTY PASS_REGULAR_EXPRESSION "750c783e6ab0b503eaa86e310a5db738")
set_property(TEST hmac_encoder_exception PROPERTY WILL_FAIL TRUE)

set_property(TEST hotp_sha1 PROPERTY PASS_REGULAR_EXPRESSION "94287082")
set_property(TEST hotp_sha256 PROPERTY PASS_REGULAR_EXPRESSION "46119246")
set_property(TEST hotp_sha512 PROPERTY PASS_REGULAR_EXPRESSION "90693936")