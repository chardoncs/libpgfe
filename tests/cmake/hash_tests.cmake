# MD5
list(APPEND HashResults_string1 "5d41402abc4b2a76b9719d911017c592")
# SHA1
list(APPEND HashResults_string1 "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d")
# SHA224
list(APPEND HashResults_string1 "ea09ae9cc6768c50fcee903ed054556e5bfc8347907f12598aa24193")
# SHA256
list(APPEND HashResults_string1 "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824") 
# SHA384
list(APPEND HashResults_string1 "59e1748777448c69de6b800d7a33bbfb9ff1b463e44354c3553bcdb9c666fa90125a3c79f90397bdf5f6a13de828684f")
# SHA512
list(APPEND HashResults_string1 "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caadae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043")
# SHA512/224
list(APPEND HashResults_string1 "fe8509ed1fb7dcefc27e6ac1a80eddbec4cb3d2c6fe565244374061c")
# SHA512/256
list(APPEND HashResults_string1 "e30d87cfa2a75db545eac4d61baf970366a8357c7f72fa95b52d0accb698f13a")
# SHA3-224
list(APPEND HashResults_string1 "b87f88c72702fff1748e58b87e9141a42c0dbedc29a78cb0d4a5cd81")
# SHA3-256
list(APPEND HashResults_string1 "3338be694f50c5f338814986cdf0686453a888b84f424d792af4b9202398f392")
# SHA3-384
list(APPEND HashResults_string1 "720aea11019ef06440fbf05d87aa24680a2153df3907b23631e7177ce620fa1330ff07c0fddee54699a4c3ee0ee9d887")
# SHA3-512
list(APPEND HashResults_string1 "75d527c368f2efe848ecf6b073a36767800805e9eef2b1857d5f984f036eb6df891d75f72d9b154518c1cd58835286d1da9a38deba3de98b5a53e5ed78a84976")

list(APPEND AlgList_file sha1 sha256 sha512 sha3_224 sha3_256 sha3_384 sha3_512)

# SHA1
list(APPEND HashResults_file1 "65d7d52df994f64a0e993794222124645242e00f")
# SHA256
list(APPEND HashResults_file1 "fa0853e947a1ba83fce63bc86ff688b559bbb3e598a9218545c288c70881d18f") 
# SHA512
list(APPEND HashResults_file1 "d4584e8dababfd80675e78a0f28a3d8130eb2da30aa01d671b916401d03475c25051fe4de8e9a61adf3852adbc1d9bbe9588feb16a99cd4e7b52db89b9f60f44")
# SHA3-224
list(APPEND HashResults_file1 "32bb7a3d1d560538df9a58518e9253a02e26f329859a7e119eb02f20")
# SHA3-256
list(APPEND HashResults_file1 "78bb1bcabdfb9242ab51f1993d76ca3e1a8372b0f8e9b1495a446ffff5de3c49")
# SHA3-384
list(APPEND HashResults_file1 "77363ff37299b19175b315e0d0a29c6e896c58b4901cd1ac6f6c56ce1b3742d4744c50bc8f04fa047f7589a62c6d7c9d")
# SHA3-512
list(APPEND HashResults_file1 "031d1ef133d02f1dbf9387354a4b8c805401bdfc2be86d522471b1905cb308c1fa8a4ed96498a4e671353bab55f517de8dc2ecd1fbde3e10e88efcc4344ca014")


foreach(item IN ZIP_LISTS AlgList HashResults_string1)
    set(test_name_c "${item_0}_string1")
    set(test_name_cpp "hash_encoder_${item_0}_string1")

    add_test(
        NAME ${test_name_c}
        COMMAND ${test_c_exe} ${item_0} ${test_text}
    )
    set_property(TEST ${test_name_c} PROPERTY PASS_REGULAR_EXPRESSION ${item_1})

    add_test(
        NAME ${test_name_cpp}
        COMMAND ${test_cpp_exe} hash_encoder ${item_0} ${test_text}
    )
    set_property(TEST ${test_name_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${item_1})
endforeach()

foreach(item IN ZIP_LISTS AlgList_file HashResults_file1)
    set(test_name_c "${item_0}_file1")

    add_test(
        NAME ${test_name_c}
        COMMAND ${test_c_exe} "${item_0}_file" test/test.txt
    )
    set_property(TEST ${test_name_c} PROPERTY PASS_REGULAR_EXPRESSION ${item_1})
endforeach()