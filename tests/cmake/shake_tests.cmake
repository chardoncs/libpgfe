list(APPEND SHAKE_lengthSize 128 150 256 370 512)
list(APPEND SHAKE_algs shake rawshake)
list(APPEND SHAKE_alg_sz 128 256)

list(APPEND SHAKE_results "8eb4b6a932f280335ee1a279f8c208a349e7bc65daf831d3021c213825292463")
list(APPEND SHAKE_results "b46431c3d65f37cafb2537e3091e4eb2bd2e958ef92eafb9d462c3deea5b2d09")
list(APPEND SHAKE_results "8db2b4fc65da8e681e297491bca4a2715bee8b4a92f9da8306fc814ffcc58c4c")
list(APPEND SHAKE_results "b0a90ec7599dbb4a81585a3dd9edf0ca682b9ea96da31f15fcfc8721cd8f7b34")
list(APPEND SHAKE_results "1234075ae4a1e77316cf2d8000974581a343b9ebbca7e3d1db83394c30f221626f594e4f0de63902349a5ea5781213215813919f92a4d86d127466e3d07e8be3")
list(APPEND SHAKE_results "3e54cfd1dfe5ab9d378ccffe0fca5d6de97189f1b705a8abb8afffbf44ff04de13f41c801c9a5c3df4283ca00b3e8ba345e638a5788ca73986b9d15e87b2e399")
list(APPEND SHAKE_results "0554aa0a35f324cd23839722f1de22a363d50c39267ff88bee3375f3d72e1dc3d7af32f161cddd35e9ec3676b3b688af1a8964358e014fa0935437290cb99960")
list(APPEND SHAKE_results "c86fe4e883d734d3534bf3f749b2a72d1bcb75ead685c70db987d85667ccf9a9a25808d7e4fa02f679d6fbb7fb96e22c5975f92071862e78c49da5d5a1712377")

list(APPEND SHAKE_results_file "7a8826e63c8d47aee480e0a4a8eb58506a1ed62ce4e12cb72fadc95e0da078ec")
list(APPEND SHAKE_results_file "7adafb40fb2531263b8cefe29ae0b3c402559ff4c0fa117f0bd55b11564e8c28")
list(APPEND SHAKE_results_file "6d4abf8c8a6ab473a19ce3e4ac1736e767abec9b03bdac4fea410cd77752ad72195652f1f45dedee66c8f71401eadda8259e0c2867613b8ef57ccb5405560d34")
list(APPEND SHAKE_results_file "0d9cd4a5f7e3c04d6d359a9e5c967ddaf542dc9f39a2adc06441aa16cc06b65d555ec98b23ce4a137f6d6282c7d8ec13cfe88b071cc8d31e9a5cff158a81db6e")

list(LENGTH SHAKE_lengthSize SHAKE_lengthSize_len)
set(i 2)
while(${i} LESS ${SHAKE_lengthSize_len})
    math(EXPR i0 "${i} - 2")
    math(EXPR i1 "${i} - 1")
    list(GET SHAKE_lengthSize ${i0} len_128)
    list(GET SHAKE_lengthSize ${i} len_256)
    list(POP_FRONT SHAKE_lengthSizeEnum)
    list(POP_FRONT SHAKE_lengthSizeEnum)
    list(APPEND SHAKE_lengthSizeEnum ${len_128} ${len_256})

    set(k 0)
    set(kf 0)

    foreach(alg_tup IN ZIP_LISTS SHAKE_alg_sz SHAKE_lengthSizeEnum)
        foreach(alg IN LISTS SHAKE_algs)
            set(t 1)
            foreach(text IN LISTS test_texts)
                set(test_name "${alg}${alg_tup_0}_bitsize${i1}_string${t}")
                set(test_name_cpp "${test_name}_cpp")

                add_test(
                    NAME ${test_name}
                    COMMAND pgfetest shake-test ${alg} ${alg_tup_0} ${alg_tup_1} ${text}
                )
                
                list(GET SHAKE_results ${k} SHAKE_result)
                math(EXPR byte_len "${alg_tup_1} / 8")
                string(SUBSTRING ${SHAKE_result} 0 ${byte_len} SHAKE_result)
                set_property(TEST ${test_name} PROPERTY PASS_REGULAR_EXPRESSION ${SHAKE_result})

                add_test(
                    NAME ${test_name_cpp}
                    COMMAND pgfetestcpp hash_encoder "${alg}${alg_tup_0}" ${alg_tup_1} ${text}
                )

                set_property(TEST ${test_name_cpp} PROPERTY PASS_REGULAR_EXPRESSION ${SHAKE_result})
                
                math(EXPR k "${k} + 1")
                math(EXPR t "${t} + 1")
            endforeach()

            set(test_name "${alg}${alg_tup_0}_bitsize${i1}_file")

            add_test(
                NAME ${test_name}
                COMMAND pgfetest shake-test_file ${alg} ${alg_tup_0} ${alg_tup_1}
            )
            
            list(GET SHAKE_results_file ${kf} SHAKE_result_file)
            math(EXPR byte_len "${alg_tup_1} / 8")
            string(SUBSTRING ${SHAKE_result_file} 0 ${byte_len} SHAKE_result_file)
            set_property(TEST ${test_name} PROPERTY PASS_REGULAR_EXPRESSION ${SHAKE_result_file})
            math(EXPR kf "${kf} + 1")
            
        endforeach()
    endforeach()


    math(EXPR i "${i} + 1")
endwhile()
