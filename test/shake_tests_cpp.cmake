set(shake_length_size1 128)
set(shake_length_size2 150)
set(shake_length_size3 256)
set(shake_length_size4 370)
set(shake_length_size5 512)
set(shake_length_size6 600)

# bitsize 1

add_test(
    NAME SHAKE128_bitsize1_string1_cpp
    COMMAND pgfetestcpp hash_encoder shake128 ${shake_length_size1} ${test_text}
)

add_test(
    NAME SHAKE256_bitsize1_string1_cpp
    COMMAND pgfetestcpp hash_encoder shake256 ${shake_length_size3} ${test_text}
)

add_test(
    NAME RawSHAKE128_bitsize1_string1_cpp
    COMMAND pgfetestcpp hash_encoder rawshake128 ${shake_length_size1} ${test_text}
)

add_test(
    NAME RawSHAKE256_bitsize1_string1_cpp
    COMMAND pgfetestcpp hash_encoder rawshake256 ${shake_length_size3} ${test_text}
)

add_test(
    NAME SHAKE128_bitsize1_string2_cpp
    COMMAND pgfetestcpp hash_encoder shake128 ${shake_length_size1} ${test_text2}
)

add_test(
    NAME SHAKE256_bitsize1_string2_cpp
    COMMAND pgfetestcpp hash_encoder shake256 ${shake_length_size3} ${test_text2}
)

add_test(
    NAME RawSHAKE128_bitsize1_string2_cpp
    COMMAND pgfetestcpp hash_encoder rawshake128 ${shake_length_size1} ${test_text2}
)

add_test(
    NAME RawSHAKE256_bitsize1_string2_cpp
    COMMAND pgfetestcpp hash_encoder rawshake256 ${shake_length_size3} ${test_text2}
)

# add_test(
#     NAME SHAKE128_bitsize1_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file shake128 ${shake_length_size1}
# )

# add_test(
#     NAME SHAKE256_bitsize1_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file shake256 ${shake_length_size3}
# )

# add_test(
#     NAME RawSHAKE128_bitsize1_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file rawshake128 ${shake_length_size1}
# )

# add_test(
#     NAME RawSHAKE256_bitsize1_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file rawshake256 ${shake_length_size3}
# )

set_property(TEST SHAKE128_bitsize1_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "8eb4b6a932f280335ee1a279f8c208a3")
set_property(TEST SHAKE256_bitsize1_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "1234075ae4a1e77316cf2d8000974581a343b9ebbca7e3d1db83394c30f22162")
set_property(TEST SHAKE128_bitsize1_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "b46431c3d65f37cafb2537e3091e4eb2")
set_property(TEST SHAKE256_bitsize1_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "3e54cfd1dfe5ab9d378ccffe0fca5d6de97189f1b705a8abb8afffbf44ff04de")
# set_property(TEST SHAKE128_bitsize1_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "7a8826e63c8d47aee480e0a4a8eb5850")
# set_property(TEST SHAKE256_bitsize1_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "6d4abf8c8a6ab473a19ce3e4ac1736e767abec9b03bdac4fea410cd77752ad72")
set_property(TEST RawSHAKE128_bitsize1_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "8db2b4fc65da8e681e297491bca4a271")
set_property(TEST RawSHAKE256_bitsize1_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "0554aa0a35f324cd23839722f1de22a363d50c39267ff88bee3375f3d72e1dc3")
set_property(TEST RawSHAKE128_bitsize1_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "b0a90ec7599dbb4a81585a3dd9edf0ca")
set_property(TEST RawSHAKE256_bitsize1_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "c86fe4e883d734d3534bf3f749b2a72d1bcb75ead685c70db987d85667ccf9a9")
# set_property(TEST RawSHAKE128_bitsize1_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "7adafb40fb2531263b8cefe29ae0b3c4")
# set_property(TEST RawSHAKE256_bitsize1_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "0d9cd4a5f7e3c04d6d359a9e5c967ddaf542dc9f39a2adc06441aa16cc06b65d")

# bitsize 2

add_test(
    NAME SHAKE128_bitsize2_string1_cpp
    COMMAND pgfetestcpp hash_encoder shake128 ${shake_length_size2} ${test_text}
)

add_test(
    NAME SHAKE256_bitsize2_string1_cpp
    COMMAND pgfetestcpp hash_encoder shake256 ${shake_length_size4} ${test_text}
)

add_test(
    NAME RawSHAKE128_bitsize2_string1_cpp
    COMMAND pgfetestcpp hash_encoder rawshake128 ${shake_length_size2} ${test_text}
)

add_test(
    NAME RawSHAKE256_bitsize2_string1_cpp
    COMMAND pgfetestcpp hash_encoder rawshake256 ${shake_length_size4} ${test_text}
)

add_test(
    NAME SHAKE128_bitsize2_string2_cpp
    COMMAND pgfetestcpp hash_encoder shake128 ${shake_length_size2} ${test_text2}
)

add_test(
    NAME SHAKE256_bitsize2_string2_cpp
    COMMAND pgfetestcpp hash_encoder shake256 ${shake_length_size4} ${test_text2}
)

add_test(
    NAME RawSHAKE128_bitsize2_string2_cpp
    COMMAND pgfetestcpp hash_encoder rawshake128 ${shake_length_size2} ${test_text2}
)

add_test(
    NAME RawSHAKE256_bitsize2_string2_cpp
    COMMAND pgfetestcpp hash_encoder rawshake256 ${shake_length_size4} ${test_text2}
)

# add_test(
#     NAME SHAKE128_bitsize2_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file shake128 ${shake_length_size2}
# )

# add_test(
#     NAME SHAKE256_bitsize2_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file shake256 ${shake_length_size4}
# )

# add_test(
#     NAME RawSHAKE128_bitsize2_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file rawshake128 ${shake_length_size2}
# )

# add_test(
#     NAME RawSHAKE256_bitsize2_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file rawshake256 ${shake_length_size4}
# )

set_property(TEST SHAKE128_bitsize2_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "8eb4b6a932f280335ee1a279f8c208a349e7")
set_property(TEST SHAKE256_bitsize2_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "1234075ae4a1e77316cf2d8000974581a343b9ebbca7e3d1db83394c30f221626f594e4f0de63902349a5ea57812")
set_property(TEST SHAKE128_bitsize2_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "b46431c3d65f37cafb2537e3091e4eb2bd2e")
set_property(TEST SHAKE256_bitsize2_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "3e54cfd1dfe5ab9d378ccffe0fca5d6de97189f1b705a8abb8afffbf44ff04de13f41c801c9a5c3df4283ca00b3e")
# set_property(TEST SHAKE128_bitsize2_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "7a8826e63c8d47aee480e0a4a8eb58506a1e")
# set_property(TEST SHAKE256_bitsize2_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "6d4abf8c8a6ab473a19ce3e4ac1736e767abec9b03bdac4fea410cd77752ad72195652f1f45dedee66c8f71401ea")
set_property(TEST RawSHAKE128_bitsize2_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "8db2b4fc65da8e681e297491bca4a2715bee")
set_property(TEST RawSHAKE256_bitsize2_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "0554aa0a35f324cd23839722f1de22a363d50c39267ff88bee3375f3d72e1dc3d7af32f161cddd35e9ec3676b3b6")
set_property(TEST RawSHAKE128_bitsize2_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "b0a90ec7599dbb4a81585a3dd9edf0ca682b")
set_property(TEST RawSHAKE256_bitsize2_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "c86fe4e883d734d3534bf3f749b2a72d1bcb75ead685c70db987d85667ccf9a9a25808d7e4fa02f679d6fbb7fb96")
# set_property(TEST RawSHAKE128_bitsize2_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "7adafb40fb2531263b8cefe29ae0b3c40255")
# set_property(TEST RawSHAKE256_bitsize2_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "0d9cd4a5f7e3c04d6d359a9e5c967ddaf542dc9f39a2adc06441aa16cc06b65d555ec98b23ce4a137f6d6282c7d8")

# bitsize 3

add_test(
    NAME SHAKE128_bitsize3_string1_cpp
    COMMAND pgfetestcpp hash_encoder shake128 ${shake_length_size3} ${test_text}
)

add_test(
    NAME SHAKE256_bitsize3_string1_cpp
    COMMAND pgfetestcpp hash_encoder shake256 ${shake_length_size5} ${test_text}
)

add_test(
    NAME RawSHAKE128_bitsize3_string1_cpp
    COMMAND pgfetestcpp hash_encoder rawshake128 ${shake_length_size3} ${test_text}
)

add_test(
    NAME RawSHAKE256_bitsize3_string1_cpp
    COMMAND pgfetestcpp hash_encoder rawshake256 ${shake_length_size5} ${test_text}
)

add_test(
    NAME SHAKE128_bitsize3_string2_cpp
    COMMAND pgfetestcpp hash_encoder shake128 ${shake_length_size3} ${test_text2}
)

add_test(
    NAME SHAKE256_bitsize3_string2_cpp
    COMMAND pgfetestcpp hash_encoder shake256 ${shake_length_size5} ${test_text2}
)

add_test(
    NAME RawSHAKE128_bitsize3_string2_cpp
    COMMAND pgfetestcpp hash_encoder rawshake128 ${shake_length_size3} ${test_text2}
)

add_test(
    NAME RawSHAKE256_bitsize3_string2_cpp
    COMMAND pgfetestcpp hash_encoder rawshake256 ${shake_length_size5} ${test_text2}
)

# add_test(
#     NAME SHAKE128_bitsize3_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file shake128 ${shake_length_size3}
# )

# add_test(
#     NAME SHAKE256_bitsize3_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file shake256 ${shake_length_size5}
# )

# add_test(
#     NAME RawSHAKE128_bitsize3_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file rawshake128 ${shake_length_size3}
# )

# add_test(
#     NAME RawSHAKE256_bitsize3_file1_cpp
#     COMMAND pgfetestcpp hash_encoder_file rawshake256 ${shake_length_size5}
# )

set_property(TEST SHAKE128_bitsize3_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "8eb4b6a932f280335ee1a279f8c208a349e7bc65daf831d3021c213825292463")
set_property(TEST SHAKE256_bitsize3_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "1234075ae4a1e77316cf2d8000974581a343b9ebbca7e3d1db83394c30f221626f594e4f0de63902349a5ea5781213215813919f92a4d86d127466e3d07e8be3")
set_property(TEST SHAKE128_bitsize3_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "b46431c3d65f37cafb2537e3091e4eb2bd2e958ef92eafb9d462c3deea5b2d09")
set_property(TEST SHAKE256_bitsize3_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "3e54cfd1dfe5ab9d378ccffe0fca5d6de97189f1b705a8abb8afffbf44ff04de13f41c801c9a5c3df4283ca00b3e8ba345e638a5788ca73986b9d15e87b2e399")
# set_property(TEST SHAKE128_bitsize3_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "7a8826e63c8d47aee480e0a4a8eb58506a1ed62ce4e12cb72fadc95e0da078ec")
# set_property(TEST SHAKE256_bitsize3_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "6d4abf8c8a6ab473a19ce3e4ac1736e767abec9b03bdac4fea410cd77752ad72195652f1f45dedee66c8f71401eadda8259e0c2867613b8ef57ccb5405560d34")
set_property(TEST RawSHAKE128_bitsize3_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "8db2b4fc65da8e681e297491bca4a2715bee8b4a92f9da8306fc814ffcc58c4c")
set_property(TEST RawSHAKE256_bitsize3_string1_cpp PROPERTY PASS_REGULAR_EXPRESSION "0554aa0a35f324cd23839722f1de22a363d50c39267ff88bee3375f3d72e1dc3d7af32f161cddd35e9ec3676b3b688af1a8964358e014fa0935437290cb99960")
set_property(TEST RawSHAKE128_bitsize3_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "b0a90ec7599dbb4a81585a3dd9edf0ca682b9ea96da31f15fcfc8721cd8f7b34")
set_property(TEST RawSHAKE256_bitsize3_string2_cpp PROPERTY PASS_REGULAR_EXPRESSION "c86fe4e883d734d3534bf3f749b2a72d1bcb75ead685c70db987d85667ccf9a9a25808d7e4fa02f679d6fbb7fb96e22c5975f92071862e78c49da5d5a1712377")
# set_property(TEST RawSHAKE128_bitsize3_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "7adafb40fb2531263b8cefe29ae0b3c402559ff4c0fa117f0bd55b11564e8c28")
# set_property(TEST RawSHAKE256_bitsize3_file1_cpp PROPERTY PASS_REGULAR_EXPRESSION "0d9cd4a5f7e3c04d6d359a9e5c967ddaf542dc9f39a2adc06441aa16cc06b65d555ec98b23ce4a137f6d6282c7d8ec13cfe88b071cc8d31e9a5cff158a81db6e")