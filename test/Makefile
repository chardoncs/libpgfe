TEST_VERSION := 0.1.0

include ../meta.mak

TEST_BIN := test
TESTS := test.c
TEST_TARGET := ../$(TARGET_DIR)/$(TEST_BIN)

all: test
	@echo 'All done'

$(TEST_TARGET):
	@echo 'Building test sources...'
	$(CC) $(OUTPUT_OPTION) $(TESTS) ../$(TARGET)

test: $(TEST_TARGET)
	@echo 'Executing tests...'
	@echo 'OUTPUT:'
	@echo ''
	@./$<
	@echo ''
	@echo 'Testing done'