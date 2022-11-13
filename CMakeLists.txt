cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(libpgfe
  VERSION 0.6.0
  DESCRIPTION "Cryptographic library"
  HOMEPAGE_URL "https://github.com/chardon55/libpgfe"
  LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

set(src_dir "src")
set(src_c_dir "${src_dir}/c")
set(src_cpp_dir "${src_dir}/cpp")
set(include_dir "include")
set(test_dir "test")

add_library(pgfe SHARED 
  ${src_c_dir}/generic.c 
  ${src_c_dir}/generic-internal.c
  ${src_c_dir}/utils.c
  ${src_c_dir}/hash/sha-internal.c
  ${src_c_dir}/hash/sha2-backend.c
  ${src_c_dir}/hash/keccak-backend.c
  ${src_c_dir}/hash/md5-backend.c
  ${src_c_dir}/hash/sha1.c ${src_c_dir}/hash/sha224.c ${src_c_dir}/hash/sha256.c ${src_c_dir}/hash/sha384.c ${src_c_dir}/hash/sha512.c
  ${src_c_dir}/hash/sha3-224.c ${src_c_dir}/hash/sha3-256.c ${src_c_dir}/hash/sha3-384.c ${src_c_dir}/hash/sha3-512.c 
  ${src_c_dir}/hash/md5.c 
  ${src_c_dir}/hash/shake.c
  ${src_c_dir}/hmac/hmac.c
  ${src_c_dir}/otp/otp-generic.c
  ${src_c_dir}/otp/hotp.c ${src_c_dir}/otp/totp.c
  ${src_c_dir}/base_encoding/base-encoding-internal.c
  ${src_c_dir}/base_encoding/base64.c ${src_c_dir}/base_encoding/base32.c ${src_c_dir}/base_encoding/base16.c
  ${src_c_dir}/blowfish/blowfish.c
  ${src_cpp_dir}/generic.cpp
  ${src_cpp_dir}/sequential_data.cpp
  ${src_cpp_dir}/utils.cpp
  ${src_cpp_dir}/algorithm_selectable.cpp
  ${src_cpp_dir}/hash/hash_encoder.cpp
  ${src_cpp_dir}/hmac/hmac_encoder.cpp
  ${src_cpp_dir}/base_encoding/abstract_base_encoding.cpp
  ${src_cpp_dir}/base_encoding/base16.cpp
  ${src_cpp_dir}/base_encoding/base32.cpp
  ${src_cpp_dir}/base_encoding/base64.cpp
  ${src_cpp_dir}/otp/abstract_otp.cpp
  ${src_cpp_dir}/otp/hotp.cpp ${src_cpp_dir}/otp/totp.cpp)
add_executable(pgfetest ${test_dir}/test.c)
add_executable(pgfetestcpp ${test_dir}/test.cpp)
# add_executable(totptest ${test_dir}/totptest.c)
# add_executable(totptestcpp ${test_dir}/totptest.cpp)

target_include_directories(pgfe PRIVATE
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
include(${test_dir}/cmake/blowfish_tests.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
