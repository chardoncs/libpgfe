set(test_dir "tests")

# CTest
include(CTest)
enable_testing()

set(test_c_exe pgfe_test_c)
set(test_cpp_exe pgfe_test_cpp)

## C lib test
add_executable(${test_c_exe} ${test_dir}/c/test.c)

target_include_directories(${test_c_exe}
  PUBLIC ${include_dir}
  PRIVATE ${test_dir}/core ${test_dir}/c/
)

target_link_libraries(${test_c_exe} pgfe)

## C++ port test
add_executable(${test_cpp_exe} ${test_dir}/cpp/test.cpp)

target_include_directories(${test_cpp_exe}
  PUBLIC ${include_dir}
  PRIVATE ${test_dir}/core ${test_dir}/cpp/
)

target_link_libraries(${test_cpp_exe} pgfe)

list(APPEND cmake_test_modules "base" "blowfish" "hash" "hmac" "otp" "shake" "util")

include(${test_dir}/${cmake_module_dir}/test_meta.cmake)

foreach(mod IN LISTS cmake_test_modules)
  include(${test_dir}/${cmake_module_dir}/${mod}_tests.cmake)
endforeach()