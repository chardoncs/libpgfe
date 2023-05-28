set(advanced_src "${src_dir}/advanced")

add_library(pgfe_advanced SHARED
  ${advanced_src}/c/fishes/blowfish.c
  ${advanced_src}/cpp/abstract_symmetric_crypter.cpp
  ${advanced_src}/cpp/fishes/blowfish.cpp
)

target_include_directories(pgfe_advanced
  PUBLIC ${include_dir}
  PRIVATE ${src_dir}
)

target_link_libraries(pgfe_advanced pgfe_core)