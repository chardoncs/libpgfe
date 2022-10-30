cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(libpgfe VERSION 0.5.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

set(src_dir "src")
set(include_dir "include")
set(test_dir "test")

add_library(pgfe SHARED 
  ${src_dir}/c/generic.c 
  ${src_dir}/c/generic-internal.c
  ${src_dir}/c/utils.c
  ${src_dir}/c/hash/sha-internal.c
  ${src_dir}/c/hash/sha2-backend.c
  ${src_dir}/c/hash/keccak-backend.c
  ${src_dir}/c/hash/md5-backend.c
  ${src_dir}/c/hash/sha1.c ${src_dir}/c/hash/sha224.c ${src_dir}/c/hash/sha256.c ${src_dir}/c/hash/sha384.c ${src_dir}/c/hash/sha512.c
  ${src_dir}/c/hash/sha3-224.c ${src_dir}/c/hash/sha3-256.c ${src_dir}/c/hash/sha3-384.c ${src_dir}/c/hash/sha3-512.c 
  ${src_dir}/c/hash/md5.c 
  ${src_dir}/c/hash/shake.c
  ${src_dir}/c/hmac/hmac.c
  ${src_dir}/c/otp/otp-generic.c
  ${src_dir}/c/otp/hotp.c ${src_dir}/c/otp/totp.c
  ${src_dir}/c/base_encoding/base-encoding-internal.c
  ${src_dir}/c/base_encoding/base64.c ${src_dir}/c/base_encoding/base32.c ${src_dir}/c/base_encoding/base16.c
  ${src_dir}/cpp/generic.cpp
  ${src_dir}/cpp/sequential_data.cpp
  ${src_dir}/cpp/utils.cpp
  ${src_dir}/cpp/algorithm_selectable.cpp
  ${src_dir}/cpp/hash/hash_encoder.cpp
  ${src_dir}/cpp/hmac/hmac_encoder.cpp
  ${src_dir}/cpp/base_encoding/abstract_base_encoding.cpp
  ${src_dir}/cpp/base_encoding/base16.cpp
  ${src_dir}/cpp/base_encoding/base32.cpp
  ${src_dir}/cpp/base_encoding/base64.cpp
  ${src_dir}/cpp/otp/abstract_otp.cpp
  ${src_dir}/cpp/otp/hotp.cpp ${src_dir}/cpp/otp/totp.cpp)
add_executable(pgfetest ${test_dir}/test.c)
add_executable(pgfetestcpp ${test_dir}/test.cpp)
# add_executable(totptest ${test_dir}/totptest.c)
# add_executable(totptestcpp ${test_dir}/totptest.cpp)

target_include_directories(pgfe PRIVATE
  ${src_dir}
  ${include_dir}
)

target_link_libraries(pgfetest pgfe)
target_link_libraries(pgfetestcpp pgfe)
# target_link_libraries(totptest pgfe)
# target_link_libraries(totptestcpp pgfe)

include(${test_dir}/cmake/test_meta.cmake)
include(${test_dir}/cmake/hash_tests.cmake)
include(${test_dir}/cmake/hmac_tests.cmake)
include(${test_dir}/cmake/util_tests.cmake)
include(${test_dir}/cmake/base_tests.cmake)
include(${test_dir}/cmake/otp_tests.cmake)
include(${test_dir}/cmake/shake_tests.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
