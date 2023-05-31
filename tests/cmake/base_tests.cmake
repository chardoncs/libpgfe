list(APPEND Base_algorithms base16 base32 base32hex base64)

# Base 16
list(APPEND Base_cipher "68656C6C6F" "686F772061726520796F753F")
# Base 32
list(APPEND Base_cipher "NBSWY3DP" "NBXXOIDBOJSSA6LPOU7Q====")
list(APPEND Base_cipher "D1IMOR3F" "D1NNE831E9II0UBFEKVG====")
# Base 64
list(APPEND Base_cipher "aGVsbG8=" "aG93IGFyZSB5b3U/")

set(i 0)
foreach(alg IN LISTS Base_algorithms)
    set(jp1 1)
    foreach(test_item IN LISTS test_texts)
        set(test_name1 "${alg}_encode${jp1}")
        set(test_name2 "${alg}_decode${jp1}")

        set(test_name1_cpp "${test_name1}_cpp")
        set(test_name2_cpp "${test_name2}_cpp")

        list(GET Base_cipher ${i} cipher)

        add_test(
            NAME ${test_name1}
            COMMAND ${test_c_exe} "${alg}-encode" ${test_item}
        )
        set_property(TEST ${test_name1} PROPERTY PASS_REGULAR_EXPRESSION ${cipher})

        add_test(
            NAME ${test_name2}
            COMMAND ${test_c_exe} "${alg}-decode" ${cipher}
        )
        set_property(TEST ${test_name2} PROPERTY PASS_REGULAR_EXPRESSION ${test_item})

        add_test(
            NAME ${test_name1_cpp}
            COMMAND ${test_cpp_exe} "${alg}_encode" ${test_item}
        )
        set_property(TEST ${test_name1_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${cipher})

        add_test(
            NAME ${test_name2_cpp}
            COMMAND ${test_cpp_exe} "${alg}_decode" ${cipher}
        )
        set_property(TEST ${test_name2_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${test_item})

        math(EXPR jp1 "${jp1} + 1")
        math(EXPR i "${i} + 1")
    endforeach()
endforeach()

add_test(
    NAME base64_multithread
    COMMAND ${test_cpp_exe} base_multithread1
)
