PROJECT := libpgfe
VERSION := 0.6.1

BUILD_DIR := build

INCLUDE_DIR := include
SRC_DIR := src

HEADER_DIR := /usr/local/include/libpgfe
LIB_DIR := /usr/lib
TARGET_DIR := $(BUILD_DIR)
TARGET_FILE := $(PROJECT).so

TARGET := $(TARGET_DIR)/$(TARGET_FILE)
TEST_TARGET := $(TARGET_DIR)/$(TEST_BIN)