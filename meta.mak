PROJECT := libpgfe
VERSION := 0.1.0

BUILD_DIR := build
TARGET_DIR := $(BUILD_DIR)/bin

OBJS_DIR := $(BUILD_DIR)/obj
OBJS := $(OBJS_DIR)/*.o

TARGET := $(TARGET_DIR)/$(PROJECT).so
TEST_TARGET := $(TARGET_DIR)/$(TEST_BIN)
LIBS := -lnettle

CC := clang
STD := c11

STD_OPTION := -std=$(STD)
