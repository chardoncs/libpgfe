PROJECT := libpgfe
VERSION := 0.7.3

BUILD_DIR := build

INCLUDE_DIR := include
SRC_DIR := src

HEADER_DIR := /usr/local/include
LIB_DIR := /usr/lib
TARGET_DIR := $(BUILD_DIR)
TARGET_FILE := $(PROJECT).so

TARGET := $(TARGET_DIR)/$(TARGET_FILE)
TEST_TARGET := $(TARGET_DIR)/$(TEST_BIN)

DEFAULT_CMAKE_TOOLCHAIN_FILE := ./cmake/toolchains/x86_64-linux-gnu-clang.cmake

NDK_ROOT := ~/Android/Sdk/ndk/23.1.7779620/