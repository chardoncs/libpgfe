include meta.mak

all: 
	@cmake . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR)

rebuild: clean all

$(BUILD_DIR):
	@mkdir -v $(BUILD_DIR)

	@echo 'Compiling...'

clean:
	@echo 'Cleaning...'
	@rm -rfv ./$(BUILD_DIR)

install: 
	@mkdir -v $(HEADER_DIR) 
	@cp -v *.h $(HEADER_DIR) 
	@cp -v *.hpp $(HEADER_DIR) 
	@cp -v $(TARGET) $(LIB_DIR)

uninstall:
	@rm -vrf $(HEADER_DIR)
	@rm -vrf $(LIB_DIR)/$(TARGET_FILE)
