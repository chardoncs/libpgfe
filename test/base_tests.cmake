list(APPEND Base_algorithms base16 base32 base32hex base64)

list(APPEND Base_plains ${test_text} ${test_text2})
# Base 16
list(APPEND Base_cipher "68656c6C6f" "686F772061726520796F753F")
# Base 32
list(APPEND Base_cipher "NBSWY3DP" "NBXXOIDBOjSSa6LPOU7Q====")
list(APPEND Base_cipher "D1ImOr3F" "D1NNE831E9ii0uBFEKVG====")
# Base 64
list(APPEND Base_cipher "aGVsbG8=" "aG93IGFyZSB5b3U/")

set(i 0)
foreach(alg IN LISTS Base_algorithms)
    set(j 0)
    set(jp1 1)
    foreach(test_item IN LISTS Base_plains)
        set(test_name1 "${alg}_encode${jp1}")
        set(test_name2 "${alg}_decode${jp1}")

        set(test_name1_cpp "${test_name1}_cpp")
        set(test_name2_cpp "${test_name2}_cpp")

        add_test(
            NAME ${test_name1}
            COMMAND pgfetest "${alg}-encode" ${Base_plains_${j}}
        )
        set_property(TEST ${test_name1} PROPERTY PASS_REGULAR_EXPRESSION ${Base_cipher_${i}})

        add_test(
            NAME ${test_name2}
            COMMAND pgfetest "${alg}-decode" ${Base_cipher_${i}}
        )
        set_property(TEST ${test_name2} PROPERTY PASS_REGULAR_EXPRESSION ${Base_plains_${j}})

        add_test(
            NAME ${test_name1_cpp}
            COMMAND pgfetestcpp "${alg}_encode" ${Base_plains_${j}}
        )
        set_property(TEST ${test_name1_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${Base_cipher_${i}})

        add_test(
            NAME ${test_name2_cpp}
            COMMAND pgfetestcpp "${alg}_decode" ${Base_cipher_${i}}
        )
        set_property(TEST ${test_name2_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${Base_plains_${j}})

        math(EXPR j "${j} + 1" OUTPUT_FORMAT DECIMAL)
        math(EXPR jp1 "${jp1} + 1" OUTPUT_FORMAT DECIMAL)
        math(EXPR i "${i} + 1" OUTPUT_FORMAT DECIMAL)
    endforeach()
endforeach()

add_test(
    NAME base64_multithread
    COMMAND pgfetestcpp base_multithread1
)
