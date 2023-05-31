list(APPEND HOTP_inputs "3132333435363738393031323334353637383930")
list(APPEND HOTP_inputs "3132333435363738393031323334353637383930313233343536373839303132")
list(APPEND HOTP_inputs "31323334353637383930313233343536373839303132333435363738393031323334353637383930313233343536373839303132333435363738393031323334")

list(APPEND HOTP_counters "1" "0x23523ED" "0x23523EC")

list(APPEND HOTP_results "94287082" "67062674" "25091201")

list(APPEND HOTP_alglist sha1 sha256 sha512)

foreach(item IN ZIP_LISTS HOTP_alglist HOTP_inputs HOTP_counters HOTP_results)
    set(test_name_c "hotp_${item_0}")
    set(test_name_cpp "hotp_${item_0}_cpp")

    add_test(
        NAME ${test_name_c}
        COMMAND ${test_c_exe} "hotp_hex_${item_0}" ${item_1} ${item_2}
    )
    set_property(TEST ${test_name_c} PROPERTY PASS_REGULAR_EXPRESSION ${item_3})

    add_test(
        NAME ${test_name_cpp}
        COMMAND ${test_cpp_exe} hotp_hex ${item_0} ${item_1} ${item_2}
    )
    set_property(TEST ${test_name_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${item_3})
endforeach()
