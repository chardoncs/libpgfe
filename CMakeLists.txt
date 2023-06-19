cmake_minimum_required(VERSION 3.26.0)

project(libpgfe
  VERSION 0.7.1
  DESCRIPTION "Cryptographic library"
  HOMEPAGE_URL "https://github.com/chardon55/libpgfe"
  LANGUAGES C CXX
)

if(CMAKE_TOOLCHAIN_FILE)
  include(${CMAKE_TOOLCHAIN_FILE})
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(src_dir "src")
set(include_dir "include")
set(cmake_module_dir "cmake")

list(APPEND cmake_modules "libpgfe")

foreach(mod IN LISTS cmake_modules)
  include(${cmake_module_dir}/targets/${mod}.cmake)
endforeach()

include(${cmake_module_dir}/tests.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
