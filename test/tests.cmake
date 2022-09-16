set(test_text "hello")
set(test_text2 "how are you?")

set(test_text_sha1 "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d")
set(test_text_sha224 "ea09ae9cc6768c50fcee903ed054556e5bfc8347907f12598aa24193")
set(test_text_sha256 "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824")
set(test_text_sha384 "59e1748777448c69de6b800d7a33bbfb9ff1b463e44354c3553bcdb9c666fa90125a3c79f90397bdf5f6a13de828684f")
set(test_text_sha512 "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caadae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043")
set(test_text_sha3_224 "b87f88c72702fff1748e58b87e9141a42c0dbedc29a78cb0d4a5cd81")
set(test_text_sha3_256 "3338be694f50c5f338814986cdf0686453a888b84f424d792af4b9202398f392")
set(test_text_sha3_384 "720aea11019ef06440fbf05d87aa24680a2153df3907b23631e7177ce620fa1330ff07c0fddee54699a4c3ee0ee9d887")
set(test_text_sha3_512 "75d527c368f2efe848ecf6b073a36767800805e9eef2b1857d5f984f036eb6df891d75f72d9b154518c1cd58835286d1da9a38deba3de98b5a53e5ed78a84976")

add_test(
    NAME SHA1_string1
    COMMAND pgfetest sha1 ${test_text}
)
add_test(
    NAME SHA1_file1
    COMMAND pgfetest sha1_file
)
add_test(
    NAME SHA224_string1
    COMMAND pgfetest sha224 ${test_text}
)
add_test(
    NAME SHA256_string1
    COMMAND pgfetest sha256 ${test_text}
)
add_test(
    NAME SHA256_file1
    COMMAND pgfetest sha256_file
)
add_test(
    NAME SHA384_string1
    COMMAND pgfetest sha384 ${test_text}
)
add_test(
    NAME SHA512_string1
    COMMAND pgfetest sha512 ${test_text}
)
add_test(
    NAME SHA512_file1
    COMMAND pgfetest sha512_file ${test_text}
)
add_test(
    NAME SHA512_224_string1
    COMMAND pgfetest sha512_224 ${test_text}
)
add_test(
    NAME SHA512_256_string1
    COMMAND pgfetest sha512_256 ${test_text}
)
add_test(
    NAME SHA3_224_string1
    COMMAND pgfetest sha3_224 ${test_text}
)
add_test(
    NAME SHA3_224_file1
    COMMAND pgfetest sha3_224_file ${test_text}
)
add_test(
    NAME SHA3_256_string1
    COMMAND pgfetest sha3_256 ${test_text}
)
add_test(
    NAME SHA3_256_file1
    COMMAND pgfetest sha3_256_file ${test_text}
)
add_test(
    NAME SHA3_384_string1
    COMMAND pgfetest sha3_384 ${test_text}
)
add_test(
    NAME SHA3_384_file1
    COMMAND pgfetest sha3_384_file ${test_text}
)
add_test(
    NAME SHA3_512_string1
    COMMAND pgfetest sha3_512 ${test_text}
)
add_test(
    NAME SHA3_512_file1
    COMMAND pgfetest sha3_512_file ${test_text}
)
add_test(
    NAME MD5_string1
    COMMAND pgfetest md5 ${test_text}
)
add_test(
    NAME string_to_hash_normal
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d"
)
add_test(
    NAME string_to_hash_odd_length
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434"
)
add_test(
    NAME string_to_hash_with_prefix
    COMMAND pgfetest string2hash "0xaaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d"
)
add_test(
    NAME string_to_hash_prefix_odd
    COMMAND pgfetest string2hash "0Xaaf4c61ddcc5e8a2dabede0f3b482cd9aea9434"
)
add_test(
    NAME string_to_hash_with_suffix
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434dH"
)
add_test(
    NAME string_to_hash_suffix_odd
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434h"
)
add_test(
    NAME string_to_hash_both_odd
    COMMAND pgfetest string2hash "0Xaaf4c61ddcc5e8a2dabede0f3b482cd9aea9434h"
)

set(test_noisy_hash "0Xaaf4c61ddc+`ZZHHgc5[e8a2dab;:edeKKKKKK0f3b48??//2cdw9aea9434h")

add_test(
    NAME hash_string_clean
    COMMAND pgfetest hash_string_clean ${test_noisy_hash}
)
add_test(
    NAME hash_string_clean_inplace
    COMMAND pgfetest hash_string_clean_inplace ${test_noisy_hash}
)
add_test(
    NAME hmac_md5_1
    COMMAND pgfetest hmac-md5 "0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b" "Hi There"
)
add_test(
    NAME hmac_md5_2
    COMMAND pgfetest hmac-md5-str "Jefe" "what do ya want for nothing?"
)
add_test(
    NAME hotp/totp1
    COMMAND pgfetest hotp_hex "3132333435363738393031323334353637383930"
)
add_test(
    NAME hotp/totp2
    COMMAND pgfetest hotp_hex_sha256 "3132333435363738393031323334353637383930313233343536373839303132"
)
add_test(
    NAME hotp/totp3
    COMMAND pgfetest hotp_hex_sha512 "31323334353637383930313233343536373839303132333435363738393031323334353637383930313233343536373839303132333435363738393031323334"
)

add_test(
    NAME base16_encode
    COMMAND pgfetest base16-encode ${test_text}
)
add_test(
    NAME base16_decode
    COMMAND pgfetest base16-decode "68656c6C6f"
)
add_test(
    NAME base32_encode1
    COMMAND pgfetest base32-encode ${test_text}
)
add_test(
    NAME base32_decode1
    COMMAND pgfetest base32-decode "NBSWY3DP"
)
add_test(
    NAME base32_encode2
    COMMAND pgfetest base32-encode ${test_text2}
)
add_test(
    NAME base32_decode2
    COMMAND pgfetest base32-decode "NBXXOIDBOjSSa6LPOU7Q===="
)
add_test(
    NAME base32hex_encode1
    COMMAND pgfetest base32hex-encode ${test_text}
)
add_test(
    NAME base32hex_decode1
    COMMAND pgfetest base32hex-decode "D1ImOr3F"
)
add_test(
    NAME base32hex_encode2
    COMMAND pgfetest base32hex-encode ${test_text2}
)
add_test(
    NAME base32hex_decode2
    COMMAND pgfetest base32hex-decode "D1NNE831E9ii0uBFEKVG===="
)
add_test(
    NAME base64_encode1
    COMMAND pgfetest base64-encode ${test_text}
)
add_test(
    NAME base64_decode1
    COMMAND pgfetest base64-decode "aGVsbG8="
)
add_test(
    NAME base64_encode2
    COMMAND pgfetest base64-encode ${test_text2}
)
add_test(
    NAME base64_decode2
    COMMAND pgfetest base64-decode "aG93IGFyZSB5b3U/"
)

include(test/shake_tests.cmake)
include(test/shake_tests_cpp.cmake)

set_property(TEST SHA1_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST SHA1_file1 PROPERTY PASS_REGULAR_EXPRESSION "65d7d52df994f64a0e993794222124645242e00f")
set_property(TEST SHA224_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha224})
set_property(TEST SHA256_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha256})
set_property(TEST SHA256_file1 PROPERTY PASS_REGULAR_EXPRESSION "fa0853e947a1ba83fce63bc86ff688b559bbb3e598a9218545c288c70881d18f")
set_property(TEST SHA384_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha384})
set_property(TEST SHA512_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha512})
set_property(TEST SHA512_file1 PROPERTY PASS_REGULAR_EXPRESSION "d4584e8dababfd80675e78a0f28a3d8130eb2da30aa01d671b916401d03475c25051fe4de8e9a61adf3852adbc1d9bbe9588feb16a99cd4e7b52db89b9f60f44")
set_property(TEST SHA512_224_string1 PROPERTY PASS_REGULAR_EXPRESSION "fe8509ed1fb7dcefc27e6ac1a80eddbec4cb3d2c6fe565244374061c")
set_property(TEST SHA512_256_string1 PROPERTY PASS_REGULAR_EXPRESSION "e30d87cfa2a75db545eac4d61baf970366a8357c7f72fa95b52d0accb698f13a")
set_property(TEST SHA3_224_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_224})
set_property(TEST SHA3_224_file1 PROPERTY PASS_REGULAR_EXPRESSION "32bb7a3d1d560538df9a58518e9253a02e26f329859a7e119eb02f20")
set_property(TEST SHA3_256_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_256})
set_property(TEST SHA3_256_file1 PROPERTY PASS_REGULAR_EXPRESSION "78bb1bcabdfb9242ab51f1993d76ca3e1a8372b0f8e9b1495a446ffff5de3c49")
set_property(TEST SHA3_384_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_384})
set_property(TEST SHA3_384_file1 PROPERTY PASS_REGULAR_EXPRESSION "77363ff37299b19175b315e0d0a29c6e896c58b4901cd1ac6f6c56ce1b3742d4744c50bc8f04fa047f7589a62c6d7c9d")
set_property(TEST SHA3_512_string1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha3_512})
set_property(TEST SHA3_512_file1 PROPERTY PASS_REGULAR_EXPRESSION "031d1ef133d02f1dbf9387354a4b8c805401bdfc2be86d522471b1905cb308c1fa8a4ed96498a4e671353bab55f517de8dc2ecd1fbde3e10e88efcc4344ca014")

set_property(TEST MD5_string1 PROPERTY PASS_REGULAR_EXPRESSION "5d41402abc4b2a76b9719d911017c592")

set_property(TEST string_to_hash_normal PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST string_to_hash_odd_length PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST string_to_hash_with_prefix PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST string_to_hash_prefix_odd PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST string_to_hash_with_suffix PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST string_to_hash_suffix_odd PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST string_to_hash_both_odd PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")

set_property(TEST hash_string_clean PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST hash_string_clean_inplace PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST hmac_md5_1 PROPERTY PASS_REGULAR_EXPRESSION "9294727a3638bb1c13f48ef8158bfc9d")
set_property(TEST hmac_md5_2 PROPERTY PASS_REGULAR_EXPRESSION "750c783e6ab0b503eaa86e310a5db738")
set_property(TEST hotp/totp1 PROPERTY PASS_REGULAR_EXPRESSION "94287082")
set_property(TEST hotp/totp2 PROPERTY PASS_REGULAR_EXPRESSION "67062674")
set_property(TEST hotp/totp3 PROPERTY PASS_REGULAR_EXPRESSION "25091201")

set_property(TEST base16_encode PROPERTY PASS_REGULAR_EXPRESSION "68656C6C6F")
set_property(TEST base16_decode PROPERTY PASS_REGULAR_EXPRESSION ${test_text})

set_property(TEST base32_encode1 PROPERTY PASS_REGULAR_EXPRESSION "NBSWY3DP")
set_property(TEST base32_decode1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text})
set_property(TEST base32_encode2 PROPERTY PASS_REGULAR_EXPRESSION "NBXXOIDBOJSSA6LPOU7Q====")
set_property(TEST base32_decode2 PROPERTY PASS_REGULAR_EXPRESSION ${test_text2})

set_property(TEST base32hex_encode1 PROPERTY PASS_REGULAR_EXPRESSION "D1IMOR3F")
set_property(TEST base32hex_decode1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text})
set_property(TEST base32hex_encode2 PROPERTY PASS_REGULAR_EXPRESSION "D1NNE831E9II0UBFEKVG====")
set_property(TEST base32hex_decode2 PROPERTY PASS_REGULAR_EXPRESSION ${test_text2})

set_property(TEST base64_encode1 PROPERTY PASS_REGULAR_EXPRESSION "aGVsbG8=")
set_property(TEST base64_decode1 PROPERTY PASS_REGULAR_EXPRESSION ${test_text})
set_property(TEST base64_encode2 PROPERTY PASS_REGULAR_EXPRESSION "aG93IGFyZSB5b3U/")
set_property(TEST base64_decode2 PROPERTY PASS_REGULAR_EXPRESSION ${test_text2})
