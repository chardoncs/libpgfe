PROJECT := libpgfe
VERSION := 0.1.0

BUILD_DIR := build
OBJS_DIR := $(BUILD_DIR)/obj
TARGET_DIR := $(BUILD_DIR)/bin

OBJS := $(addprefix $(OBJS_DIR)/,$(PROJECT).o)
TARGET := $(TARGET_DIR)/$(PROJECT).so
LIBS := -lnettle

CC := clang
# CC := gcc
STD := c11

STD_OPTION := -std=$(STD)

all: clean $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -shared $(OUTPUT_OPTION) $^

$(OBJS): $(BUILD_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) -c $(OUTPUT_OPTION) $< $(STD_OPTION)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	mkdir -p $(OBJS_DIR)
	mkdir -p $(TARGET_DIR)

start:
	./$(TARGET) $^

clean:
	@rm -rfv ./$(BUILD_DIR)
