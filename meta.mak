PROJECT := libpgfe
VERSION := 0.1.0

BUILD_DIR := build
TARGET_DIR := $(BUILD_DIR)/bin

OBJS_DIR := $(BUILD_DIR)/obj
OBJS := $(addprefix $(OBJS_DIR)/,generic.o generic-internal.o templates.o sha1.o sha224.o sha256.o sha384.o sha512.o sha3-224.o sha3-256.o sha3-384.o sha3-512.o md5.o hmac.o utils.o pgfe.o)

TARGET := $(TARGET_DIR)/$(PROJECT).so
TEST_TARGET := $(TARGET_DIR)/$(TEST_BIN)
LIBS := -lnettle

CC := clang
STD := c11

STD_OPTION := -std=$(STD)
