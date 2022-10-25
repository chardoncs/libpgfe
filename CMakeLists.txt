cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(libpgfe VERSION 0.4.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

add_library(pgfe SHARED 
    src/generic.c 
    src/generic-internal.c
    src/templates.c
    src/utils.c
    src/sha-internal.c
    src/sha2-backend.c
    src/keccak-backend.c
    src/md5-backend.c
    src/sha1.c src/sha224.c src/sha256.c src/sha384.c src/sha512.c src/sha3-224.c src/sha3-256.c src/sha3-384.c src/sha3-512.c 
    src/md5.c 
    src/shake.c
    src/hmac.c
    src/otp-generic.c
    src/hotp.c src/totp.c
    src/base-encoding-internal.c
    src/base64.c src/base32.c src/base16.c
    src/sequential_data.cpp
    src/utils.cpp
    src/algorithm_selectable.cpp
    src/hash_encoder.cpp
    src/hmac_encoder.cpp
    src/abstract_base_encoding.cpp
    src/base16.cpp
    src/base32.cpp
    src/base64.cpp
    src/abstract_otp.cpp
    src/hotp.cpp src/totp.cpp)
add_executable(pgfetest test/test.c)
# add_executable(totptest test/totptest.c)
# add_executable(totptestcpp test/totptest.cpp)

target_include_directories(pgfe PRIVATE
  src
  include
)

add_executable(pgfetestcpp test/test.cpp)

target_link_libraries(pgfetest pgfe)
# target_link_libraries(totptest pgfe)
target_link_libraries(pgfetestcpp pgfe)
# target_link_libraries(totptestcpp pgfe)

include(test/cmake/test_meta.cmake)
include(test/cmake/hash_tests.cmake)
include(test/cmake/hmac_tests.cmake)
include(test/cmake/util_tests.cmake)
include(test/cmake/base_tests.cmake)
include(test/cmake/otp_tests.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
