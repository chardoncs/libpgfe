list(APPEND Blowfish_keys "TESTKEY")
list(APPEND Blowfish_plains "4294967298")
list(APPEND Blowfish_crypts "DF333FD230A71BB4")

set(i 1)
foreach(item IN ZIP_LISTS Blowfish_keys Blowfish_plains Blowfish_crypts)
    set(test_name_enc "blowfish_encrypt${i}")
    set(test_name_dec "blowfish_decrypt${i}")

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
