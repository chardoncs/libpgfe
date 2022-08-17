cmake_minimum_required(VERSION 3.0.0)
project(libpgfe VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

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
    hotp.c
    pgfe.c)
add_executable(pgfetest test/test.c)

target_link_libraries(pgfe nettle)
target_link_libraries(pgfetest pgfe)

include(tests.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
