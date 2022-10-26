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
    ${src_dir}/generic.c 
    ${src_dir}/generic-internal.c
    ${src_dir}/templates.c
    ${src_dir}/utils.c
    ${src_dir}/sha-internal.c
    ${src_dir}/sha2-backend.c
    ${src_dir}/keccak-backend.c
    ${src_dir}/md5-backend.c
    ${src_dir}/sha1.c ${src_dir}/sha224.c ${src_dir}/sha256.c ${src_dir}/sha384.c ${src_dir}/sha512.c
    ${src_dir}/sha3-224.c ${src_dir}/sha3-256.c ${src_dir}/sha3-384.c ${src_dir}/sha3-512.c 
    ${src_dir}/md5.c 
    ${src_dir}/shake.c
    ${src_dir}/hmac.c
    ${src_dir}/otp-generic.c
    ${src_dir}/hotp.c ${src_dir}/totp.c
    ${src_dir}/base-encoding-internal.c
    ${src_dir}/base64.c ${src_dir}/base32.c ${src_dir}/base16.c
    ${src_dir}/sequential_data.cpp
    ${src_dir}/utils.cpp
    ${src_dir}/algorithm_selectable.cpp
    ${src_dir}/hash_encoder.cpp
    ${src_dir}/hmac_encoder.cpp
    ${src_dir}/abstract_base_encoding.cpp
    ${src_dir}/base16.cpp
    ${src_dir}/base32.cpp
    ${src_dir}/base64.cpp
    ${src_dir}/abstract_otp.cpp
    ${src_dir}/hotp.cpp ${src_dir}/totp.cpp)
add_executable(pgfetest ${test_dir}/test.c)
# add_executable(totptest ${test_dir}/totptest.c)
# add_executable(totptestcpp ${test_dir}/totptest.cpp)
add_executable(pgfetestcpp ${test_dir}/test.cpp)

target_include_directories(pgfe PRIVATE
  ${src_dir}
  ${include_dir}
)

target_link_libraries(pgfetest pgfe)
# target_link_libraries(totptest pgfe)
target_link_libraries(pgfetestcpp pgfe)
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
