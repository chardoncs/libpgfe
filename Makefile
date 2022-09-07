include meta.mak

all: 
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR)
	@echo 'Building done'

rebuild: clean all

$(BUILD_DIR):
	@mkdir -v $(BUILD_DIR)

clean:
	@echo 'Cleaning...'
	@rm -rf ./$(BUILD_DIR)
	@echo 'Cleaning done'

install: 
	@mkdir -v $(HEADER_DIR) 
	@cp -v *.h $(HEADER_DIR) 
	@cp -v *.hpp $(HEADER_DIR) 
	@cp -v $(TARGET) $(LIB_DIR)

uninstall:
	@rm -vrf $(HEADER_DIR)
	@rm -vrf $(LIB_DIR)/$(TARGET_FILE)
