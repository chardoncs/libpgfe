list(APPEND HMAC_keys "0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b" "Jefe")
list(APPEND HMAC_data "Hi There" "what do ya want for nothing?")
list(APPEND HMAC_alglist md5 sha1 sha224 sha256 sha384 sha512)

# MD5
list(APPEND HMAC_results "9294727a3638bb1c13f48ef8158bfc9d" "750c783e6ab0b503eaa86e310a5db738")
# SHA1
list(APPEND HMAC_results "675b0b3a1b4ddf4e124872da6c2f632bfed957e9" "effcdf6ae5eb2fa2d27416d5f184df9c259a7c79")
# SHA224
list(APPEND HMAC_results "4e841ce7a4ae83fbcf71e3cd64bfbf277f73a14680aae8c518ac7861")
list(APPEND HMAC_results "a30e01098bc6dbbf45690f3a7e9e6d0f8bbea2a39e6148008fd05e44")
# SHA256
list(APPEND HMAC_results "492ce020fe2534a5789dc3848806c78f4f6711397f08e7e7a12ca5a4483c8aa6")
list(APPEND HMAC_results "5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843")
# SHA384
list(APPEND HMAC_results "7afaa633e20d379b02395915fbc385ff8dc27dcd3885e1068ab942eeab52ec1f20ad382a92370d8b2e0ac8b83c4d53bf")
list(APPEND HMAC_results "af45d2e376484031617f78d2b58a6b1b9c7ef464f5a01b47e42ec3736322445e8e2240ca5e69e2c78b3239ecfab21649")
# SHA512
list(APPEND HMAC_results "7641c48a3b4aa8f887c07b3e83f96affb89c978fed8c96fcbbf4ad596eebfe496f9f16da6cd080ba393c6f365ad72b50d15c71bfb1d6b81f66a911786c6ce932")
list(APPEND HMAC_results "164b7a7bfcf819e2e395fbe73b56e0a387bd64222e831fd610270cd7ea2505549758bf75c05a994a6d034f65f8f0e6fdcaeab1a34d4a6b4b636e070a38bce737")

set(i 0)
foreach(alg IN LISTS HMAC_alglist)
    set(jp1 1)
    foreach(tup IN ZIP_LISTS HMAC_keys HMAC_data)
        set(test_name_c "hmac_${alg}_${jp1}")
        set(test_name_cpp "hmac_encoder_${alg}_${jp1}")

        list(GET HMAC_results ${i} result)

        add_test(
            NAME ${test_name_c}
            COMMAND ${test_c_exe} hmac ${alg} ${tup_0} ${tup_1}
        )    
        set_property(TEST ${test_name_c} PROPERTY PASS_REGULAR_EXPRESSION ${result})

        add_test(
            NAME ${test_name_cpp}
            COMMAND ${test_cpp_exe} hmac_encoder ${alg} ${tup_0} ${tup_1}
        )
        set_property(TEST ${test_name_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${result})
    
        math(EXPR i "${i} + 1")
        math(EXPR jp1 "${jp1} + 1")
    endforeach()
endforeach()
