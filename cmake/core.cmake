set(core_src "${src_dir}/core")

add_library(pgfe_core SHARED
  # General
  ${core_src}/c/generic.c
  ${core_src}/c/generic-internal.c
  ${core_src}/c/utils.c
  ${core_src}/cpp/generic.cpp
  ${core_src}/cpp/algorithm_selectable.cpp
  ${core_src}/cpp/sequential_data.cpp
  ${core_src}/cpp/utils.cpp
  # Bases
  ${core_src}/c/bases/base-encoding-internal.c
  ${core_src}/c/bases/base16.c
  ${core_src}/c/bases/base32.c
  ${core_src}/c/bases/base64.c
  ${core_src}/cpp/bases/abstract_base_encoding.cpp
  ${core_src}/cpp/bases/base16.cpp
  ${core_src}/cpp/bases/base32.cpp
  ${core_src}/cpp/bases/base64.cpp
  # Hashes
  ${core_src}/c/hashes/keccak-backend.c
  ${core_src}/c/hashes/md5-backend.c
  ${core_src}/c/hashes/md5.c
  ${core_src}/c/hashes/sha-internal.c
  ${core_src}/c/hashes/sha1.c
  ${core_src}/c/hashes/sha2-backend.c
  ${core_src}/c/hashes/sha3-224.c
  ${core_src}/c/hashes/sha3-256.c
  ${core_src}/c/hashes/sha3-384.c
  ${core_src}/c/hashes/sha3-512.c
  ${core_src}/c/hashes/sha224.c
  ${core_src}/c/hashes/sha256.c
  ${core_src}/c/hashes/sha384.c
  ${core_src}/c/hashes/sha512.c
  ${core_src}/c/hashes/shake.c
  ${core_src}/cpp/hashes/hash_encoder.cpp
  # HMAC
  ${core_src}/c/hmac/hmac.c
  ${core_src}/cpp/hmac/hmac_encoder.cpp
)

target_include_directories(pgfe_core
  PUBLIC ${include_dir}
  PRIVATE ${src_dir}
)