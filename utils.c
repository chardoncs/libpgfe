#include "utils.h"

inline void __pgfe_arrinit(pgfe_encode_t arr[], const size_t size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

inline void __pgfe_arrcpy(pgfe_encode_t dest[], const size_t dest_s, const pgfe_encode_t src[], const size_t src_s) {
    size_t cpy_s = dest_s > src_s ? src_s : dest_s;
    memcpy(dest, src, cpy_s);
    __pgfe_arrinit(dest + cpy_s, dest_s - cpy_s);
}