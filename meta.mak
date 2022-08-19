PROJECT := libpgfe
VERSION := 0.1.0

BUILD_DIR := build
TARGET_DIR := $(BUILD_DIR)

OBJS_DIR := $(BUILD_DIR)/obj
OBJS := $(addprefix $(OBJS_DIR)/,\
generic.c.o \
generic-internal.c.o utils.c.o templates.c.o sha1.c.o sha224.c.o sha256.c.o sha384.c.o \
sha512.c.o sha3-224.c.o sha3-256.c.o sha3-384.c.o sha3-512.c.o md5.c.o hmac.c.o otp-generic.c.o hotp.c.o totp.c.o \
base-encoding-internal.c.o base64.c.o base32.c.o base16.c.o\
pgfe.c.o\
sequential_data.cpp.o\
utils.cpp.o\
hash_encoder.cpp.o\
hmac_encoder.cpp.o\
abstract_base_encoding.cpp.o\
base16.cpp.o\
base32.cpp.o\
base64.cpp.o\
abstract_otp.cpp.o\
hotp.cpp.o\
totp.cpp.o)

TARGET := $(TARGET_DIR)/$(PROJECT).so
TEST_TARGET := $(TARGET_DIR)/$(TEST_BIN)
LIBS := -lnettle

CC := clang
CPP := clang++
STD := c11
STD_CPP := c++11

STD_OPTION := -std=$(STD)
STD_CPP_OPTION := -std=$(STD_CPP)
