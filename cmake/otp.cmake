set(otp_src "${src_dir}/otp")

add_library(pgfe_otp SHARED
  ${otp_src}/c/otp-generic.c
  ${otp_src}/c/hotp.c
  ${otp_src}/c/totp.c
  ${otp_src}/cpp/abstract_otp.cpp
  ${otp_src}/cpp/hotp.cpp
  ${otp_src}/cpp/totp.cpp
)

target_include_directories(pgfe_otp
  PUBLIC ${include_dir}
  PRIVATE ${src_dir}
)

target_link_libraries(pgfe_otp pgfe_core)