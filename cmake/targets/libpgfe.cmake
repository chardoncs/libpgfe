add_library(pgfe SHARED 
  # Core
  ${src_dir}/core/generic.c 
  ${src_dir}/core/generic-internal.c
  ${src_dir}/core/utils.c
  ${src_dir}/core/abstract_symmetric_crypter.cpp
  ${src_dir}/core/algorithm_selectable.cpp
  ${src_dir}/core/generic.cpp
  ${src_dir}/core/sequential_data.cpp
  ${src_dir}/core/utils.cpp
  # Hashes
  ${src_dir}/hashes/sha-internal.c
  ${src_dir}/hashes/sha2-backend.c
  ${src_dir}/hashes/keccak-backend.c
  ${src_dir}/hashes/md5-backend.c
  ${src_dir}/hashes/sha1.c
  ${src_dir}/hashes/sha224.c
  ${src_dir}/hashes/sha256.c
  ${src_dir}/hashes/sha384.c
  ${src_dir}/hashes/sha512.c
  ${src_dir}/hashes/sha3-224.c
  ${src_dir}/hashes/sha3-256.c
  ${src_dir}/hashes/sha3-384.c
  ${src_dir}/hashes/sha3-512.c 
  ${src_dir}/hashes/md5.c 
  ${src_dir}/hashes/shake.c
  ${src_dir}/hashes/hash_encoder.cpp
  # HMAC
  ${src_dir}/hmac/hmac.c
  ${src_dir}/hmac/hmac_encoder.cpp
  # Base encoding
  ${src_dir}/base_encoding/base-encoding-internal.c
  ${src_dir}/base_encoding/base64.c
  ${src_dir}/base_encoding/base32.c
  ${src_dir}/base_encoding/base16.c
  ${src_dir}/base_encoding/abstract_base_encoding.cpp
  ${src_dir}/base_encoding/base16.cpp
  ${src_dir}/base_encoding/base32.cpp
  ${src_dir}/base_encoding/base64.cpp
  # OTP
  ${src_dir}/otp/otp-generic.c
  ${src_dir}/otp/hotp.c
  ${src_dir}/otp/totp-internal.c
  ${src_dir}/otp/totp.c
  ${src_dir}/otp/abstract_otp.cpp
  ${src_dir}/otp/hotp.cpp
  ${src_dir}/otp/totp.cpp
  # Fishes (Blowfish, Twofish, Threefish etc.)
  ${src_dir}/fishes/blowfish.c
  ${src_dir}/fishes/blowfish.cpp
)

target_include_directories(pgfe
  PUBLIC ${include_dir}
  PRIVATE ${src_dir}
)
