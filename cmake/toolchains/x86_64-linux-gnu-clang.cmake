set(CMAKE_SYSTEM_NAME Linux)


set(triple x86_64-linux-gnu)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET ${triple})

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_COMPILER_TARGET ${triple})

SET(CMAKE_AR llvm-ar)
SET(CMAKE_RANLIB llvm-ranlib)
set(CMAKE_ADDR2LINE llvm-addr2line)

set(CMAKE_C_COMPILER_AR llvm-ar)
set(CMAKE_C_COMPILER_RANLIB llvm-ranlib)

set(CMAKE_CXX_COMPILER_AR llvm-ar)
set(CMAKE_CXX_COMPILER_RANLIB llvm-ranlib)

set(CMAKE_LINKER ld.lld)
add_link_options("-fuse-ld=lld")

set(CMAKE_NM llvm-nm)
set(CMAKE_OBJCOPY llvm-objcopy)
set(CMAKE_OBJDUMP llvm-objdump)

set(CMAKE_READELF llvm-readelf)
set(CMAKE_READOBJ llvm-readobj)
set(CMAKE_STRIP llvm-strip)