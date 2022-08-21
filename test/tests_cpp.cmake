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

add_test(
    NAME base16_encode_cpp
    COMMAND pgfetestcpp base16_encode ${test_text}
)
add_test(
    NAME base16_decode_cpp
    COMMAND pgfetestcpp base16_decode "68656c6C6f"
)
add_test(
    NAME base32_encode1_cpp
    COMMAND pgfetestcpp base32_encode ${test_text}
)
add_test(
    NAME base32_decode1_cpp
    COMMAND pgfetestcpp base32_decode "NBSWY3DP"
)
add_test(
    NAME base32_encode2_cpp
    COMMAND pgfetestcpp base32_encode ${test_text2}
)
add_test(
    NAME base32_decode2_cpp
    COMMAND pgfetestcpp base32_decode "NBXXOIDBOjSSa6LPOU7Q===="
)
add_test(
    NAME base32hex_encode1_cpp
    COMMAND pgfetestcpp base32hex_encode ${test_text}
)
add_test(
    NAME base32hex_decode1_cpp
    COMMAND pgfetestcpp base32hex_decode "D1ImOr3F"
)
add_test(
    NAME base32hex_encode2_cpp
    COMMAND pgfetestcpp base32hex_encode ${test_text2}
)
add_test(
    NAME base32hex_decode2_cpp
    COMMAND pgfetestcpp base32hex_decode "D1NNE831E9ii0uBFEKVG===="
)
add_test(
    NAME base64_encode1_cpp
    COMMAND pgfetestcpp base64_encode ${test_text}
)
add_test(
    NAME base64_decode1_cpp
    COMMAND pgfetestcpp base64_decode "aGVsbG8="
)
add_test(
    NAME base64_encode2_cpp
    COMMAND pgfetestcpp base64_encode ${test_text2}
)
add_test(
    NAME base64_decode2_cpp
    COMMAND pgfetestcpp base64_decode "aG93IGFyZSB5b3U/"
)
add_test(
    NAME base64_multithread
    COMMAND pgfetestcpp base_multithread1
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

set_property(TEST base16_encode_cpp PROPERTY PASS_REGULAR_EXPRESSION "68656C6C6F")
set_property(TEST base16_decode_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text})

set_property(TEST base32_encode1_cpp PROPERTY PASS_REGULAR_EXPRESSION "NBSWY3DP")
set_property(TEST base32_decode1_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text})
set_property(TEST base32_encode2_cpp PROPERTY PASS_REGULAR_EXPRESSION "NBXXOIDBOJSSA6LPOU7Q====")
set_property(TEST base32_decode2_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text2})

set_property(TEST base32hex_encode1_cpp PROPERTY PASS_REGULAR_EXPRESSION "D1IMOR3F")
set_property(TEST base32hex_decode1_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text})
set_property(TEST base32hex_encode2_cpp PROPERTY PASS_REGULAR_EXPRESSION "D1NNE831E9II0UBFEKVG====")
set_property(TEST base32hex_decode2_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text2})

set_property(TEST base64_encode1_cpp PROPERTY PASS_REGULAR_EXPRESSION "aGVsbG8=")
set_property(TEST base64_decode1_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text})
set_property(TEST base64_encode2_cpp PROPERTY PASS_REGULAR_EXPRESSION "aG93IGFyZSB5b3U/")
set_property(TEST base64_decode2_cpp PROPERTY PASS_REGULAR_EXPRESSION ${test_text2})