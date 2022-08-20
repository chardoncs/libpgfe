cmake_minimum_required(VERSION 3.0.0)
project(libpgfe VERSION 0.1.1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

include(CTest)
enable_testing()

add_library(pgfe SHARED 
    generic.c 
    generic-internal.c
    templates.c
    utils.c
    sha1.c sha224.c sha256.c sha384.c sha512.c sha3-224.c sha3-256.c sha3-384.c sha3-512.c 
    md5.c 
    hmac.c
    otp-generic.c
    hotp.c totp.c
    base-encoding-internal.c
    base64.c base32.c base16.c
    pgfe.c
    sequential_data.cpp
    utils.cpp
    hash_encoder.cpp
    hmac_encoder.cpp
    abstract_base_encoding.cpp
    base16.cpp
    base32.cpp
    base64.cpp
    abstract_otp.cpp
    hotp.cpp totp.cpp)
add_executable(pgfetest test/test.c)
# add_executable(totptest test/totptest.c)
# add_executable(totptestcpp test/totptest.cpp)

add_executable(pgfetestcpp test/test.cpp)

target_link_libraries(pgfe nettle)
target_link_libraries(pgfetest pgfe)
# target_link_libraries(totptest pgfe)
target_link_libraries(pgfetestcpp pgfe)
# target_link_libraries(totptestcpp pgfe)

include(test/tests.cmake)
include(test/tests_cpp.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
