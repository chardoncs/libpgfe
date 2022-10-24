set(test_text_sha1 "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d")
set(test_noisy_hash "0Xaaf4c61ddc+`ZZHHgc5[e8a2dab;:edeKKKKKK0f3b48??//2cdw9aea9434h")

add_test(
    NAME string_to_hash_normal
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d"
)
add_test(
    NAME string_to_hash_odd_length
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434"
)
add_test(
    NAME string_to_hash_with_prefix
    COMMAND pgfetest string2hash "0xaaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d"
)
add_test(
    NAME string_to_hash_prefix_odd
    COMMAND pgfetest string2hash "0Xaaf4c61ddcc5e8a2dabede0f3b482cd9aea9434"
)
add_test(
    NAME string_to_hash_with_suffix
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434dH"
)
add_test(
    NAME string_to_hash_suffix_odd
    COMMAND pgfetest string2hash "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434h"
)
add_test(
    NAME string_to_hash_both_odd
    COMMAND pgfetest string2hash "0Xaaf4c61ddcc5e8a2dabede0f3b482cd9aea9434h"
)

add_test(
    NAME hash_string_clean
    COMMAND pgfetest hash_string_clean ${test_noisy_hash}
)
add_test(
    NAME hash_string_clean_inplace
    COMMAND pgfetest hash_string_clean_inplace ${test_noisy_hash}
)

set_property(TEST string_to_hash_normal PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST string_to_hash_odd_length PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST string_to_hash_with_prefix PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST string_to_hash_prefix_odd PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST string_to_hash_with_suffix PROPERTY PASS_REGULAR_EXPRESSION ${test_text_sha1})
set_property(TEST string_to_hash_suffix_odd PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST string_to_hash_both_odd PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")

set_property(TEST hash_string_clean PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")
set_property(TEST hash_string_clean_inplace PROPERTY PASS_REGULAR_EXPRESSION "0?aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434")