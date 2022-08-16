cmake_minimum_required(VERSION 3.0.0)
project(libpgfe VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

include(CTest)
enable_testing()

add_library(pgfe SHARED 
    generic.c 
    templates.c
    utils.c
    sha1.c sha224.c sha256.c sha384.c sha512.c sha3-224.c sha3-256.c sha3-384.c sha3-512.c 
    md5.c 
    hmac.c
    pgfe.c)
add_executable(pgfetest test/test.c)

target_link_libraries(pgfe nettle)
target_link_libraries(pgfetest pgfe)

set(test_text hello)

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
    NAME SHA384_string1
    COMMAND pgfetest sha384 ${test_text}
)
add_test(
    NAME SHA512_string1
    COMMAND pgfetest sha512 ${test_text}
)
add_test(
    NAME SHA3_224_string1
    COMMAND pgfetest sha3_224 ${test_text}
)
add_test(
    NAME SHA3_256_string1
    COMMAND pgfetest sha3_256 ${test_text}
)
add_test(
    NAME SHA3_384_string1
    COMMAND pgfetest sha3_384 ${test_text}
)
add_test(
    NAME SHA3_512_string1
    COMMAND pgfetest sha3_512 ${test_text}
)
add_test(
    NAME MD5_string1
    COMMAND pgfetest md5 ${test_text}
)
add_test(
    NAME SHA256_frontend
    COMMAND pgfetest fe-sha256 ${test_text}
)

set_property(TEST SHA1_string1 PROPERTY PASS_REGULAR_EXPRESSION "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d")
set_property(TEST SHA1_file1 PROPERTY PASS_REGULAR_EXPRESSION "65d7d52df994f64a0e993794222124645242e00f")
set_property(TEST SHA224_string1 PROPERTY PASS_REGULAR_EXPRESSION "ea09ae9cc6768c50fcee903ed054556e5bfc8347907f12598aa24193")
set_property(TEST SHA256_string1 PROPERTY PASS_REGULAR_EXPRESSION "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824")
set_property(TEST SHA384_string1 PROPERTY PASS_REGULAR_EXPRESSION "59e1748777448c69de6b800d7a33bbfb9ff1b463e44354c3553bcdb9c666fa90125a3c79f90397bdf5f6a13de828684f")
set_property(TEST SHA512_string1 PROPERTY PASS_REGULAR_EXPRESSION "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caadae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043")
set_property(TEST SHA3_224_string1 PROPERTY PASS_REGULAR_EXPRESSION "b87f88c72702fff1748e58b87e9141a42c0dbedc29a78cb0d4a5cd81")
set_property(TEST SHA3_256_string1 PROPERTY PASS_REGULAR_EXPRESSION "3338be694f50c5f338814986cdf0686453a888b84f424d792af4b9202398f392")
set_property(TEST SHA3_384_string1 PROPERTY PASS_REGULAR_EXPRESSION "720aea11019ef06440fbf05d87aa24680a2153df3907b23631e7177ce620fa1330ff07c0fddee54699a4c3ee0ee9d887")
set_property(TEST SHA3_512_string1 PROPERTY PASS_REGULAR_EXPRESSION "75d527c368f2efe848ecf6b073a36767800805e9eef2b1857d5f984f036eb6df891d75f72d9b154518c1cd58835286d1da9a38deba3de98b5a53e5ed78a84976")
set_property(TEST MD5_string1 PROPERTY PASS_REGULAR_EXPRESSION "5d41402abc4b2a76b9719d911017c592")
set_property(TEST SHA256_frontend PROPERTY PASS_REGULAR_EXPRESSION "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
