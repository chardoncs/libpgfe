set(CMAKE_SYSTEM_NAME Linux)


set(arch aarch64)
set(arch_alt arm64)
set(subarch v8a)
set(triple ${arch}-linux-android)

include(${CMAKE_CURRENT_LIST_DIR}/../config/ndk_root.cmake)

if(NOT HOST_ID)
  set(HOST_ID linux-x86_64)
endif()

if(NOT ANDROID_PLATFORM_VERSION)
  set(ANDROID_PLATFORM_VERSION 23)
endif()

set(ANDROID_ABI ${arch_alt}-${subarch})
set(ANDROID_PLATFORM android-${ANDROID_PLATFORM_VERSION})
set(ANDROID_STL c++_shared)

include(${NDK_ROOT}/build/cmake/android.toolchain.cmake)