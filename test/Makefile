TEST_VERSION := 0.1.0

include ../meta.mak

TEST_BIN := test
TESTS := test.c
TEST_TARGET := ../$(TARGET_DIR)/$(TEST_BIN)

all: test
	@echo 'All done'

$(TEST_TARGET): clean
	@echo 'Building test sources...'
	$(CC) $(OUTPUT_OPTION) $(TESTS) ../$(TARGET)

test: $(TEST_TARGET)
	@echo 'Executing tests...'
	@echo 'OUTPUT:'
	@echo ''
	@./$< sha1
	@echo ''
	@./$< sha1_file
	@echo ''
	@./$< sha224
	@echo ''
	@./$< sha256
	@echo ''
	@./$< sha384
	@echo ''
	@./$< sha512
	@echo ''
	@./$< sha3_224
	@echo ''
	@./$< sha3_256
	@echo ''
	@./$< sha3_384
	@echo ''
	@./$< sha3_512
	@echo ''
	@./$< md5
	@echo ''
	@echo 'Testing done'

clean:
	@rm -vf $(TEST_TARGET)