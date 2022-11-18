list(APPEND Blowfish_keys "TESTKEY")
list(APPEND Blowfish_plains "4294967298")
list(APPEND Blowfish_crypts "DF333FD230A71BB4")

list(APPEND Blowfish_keys_str "TESTKEY" "TESTKEY")
list(APPEND Blowfish_plains_str "Hello" "how are you?")
list(APPEND Blowfish_crypts_str "9fba2e509bd3230c" "f31bc2f912c7a2e27b67105e57d58c86")

set(i 1)
foreach(item IN ZIP_LISTS Blowfish_keys Blowfish_plains Blowfish_crypts)
    set(test_name_enc "blowfish_encrypt_unit${i}")
    set(test_name_dec "blowfish_decrypt_unit${i}")

    add_test(
        NAME ${test_name_enc}
        COMMAND pgfetest blowfish_enc_unit ${item_0} ${item_1}
    )
    set_property(TEST ${test_name_enc} PROPERTY PASS_REGULAR_EXPRESSION ${item_2})

    add_test(
        NAME ${test_name_dec}
        COMMAND pgfetest blowfish_dec_unit ${item_0} ${item_2}
    )
    set_property(TEST ${test_name_dec} PROPERTY PASS_REGULAR_EXPRESSION ${item_1})

    math(EXPR i "${i} + 1")
endforeach()

set(i 1)
foreach(item IN ZIP_LISTS Blowfish_keys_str Blowfish_plains_str Blowfish_crypts_str)
    set(test_name_enc "blowfish_encrypt_str${i}")
    set(test_name_dec "blowfish_decrypt_str${i}")
    set(test_name_enc_cpp "${test_name_enc}_cpp")
    set(test_name_dec_cpp "${test_name_dec}_cpp")

    add_test(
        NAME ${test_name_enc}
        COMMAND pgfetest blowfish_enc_str ${item_0} ${item_1}
    )
    set_property(TEST ${test_name_enc} PROPERTY PASS_REGULAR_EXPRESSION ${item_2})

    add_test(
        NAME ${test_name_dec}
        COMMAND pgfetest blowfish_dec_str ${item_0} ${item_2}
    )
    set_property(TEST ${test_name_dec} PROPERTY PASS_REGULAR_EXPRESSION ${item_1})

    add_test(
        NAME ${test_name_enc_cpp}
        COMMAND pgfetestcpp blowfish_encrypt ${item_0} ${item_1}
    )
    set_property(TEST ${test_name_enc_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${item_2})

    add_test(
        NAME ${test_name_dec_cpp}
        COMMAND pgfetestcpp blowfish_decrypt ${item_0} ${item_2}
    )
    set_property(TEST ${test_name_dec_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${item_1})

    math(EXPR i "${i} + 1")
endforeach()