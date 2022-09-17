include meta.mak

all: 
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR) --config Release -j18
	@echo 'Building done'

rebuild: clean all

$(BUILD_DIR):
	@mkdir -v $(BUILD_DIR)

clean:
	@echo 'Cleaning...'
	@rm -rf ./$(BUILD_DIR)
	@echo 'Cleaning done'

ctest: all
	@ctest --test-dir $(BUILD_DIR) -C Release

install: all
	@echo 'Installing headers...'
	@mkdir -v $(HEADER_DIR) 
	@cp -v $(INCLUDE_DIR)/* $(HEADER_DIR) 
	@echo done
	@echo 'Installing shared library...'
	@cp -v $(TARGET) $(LIB_DIR)
	@echo 'done'

uninstall:
	@echo 'Removing headers...'
	@rm -vrf $(HEADER_DIR)
	@echo done
	@echo 'Removing shared library...'
	@rm -vrf $(LIB_DIR)/$(TARGET_FILE)
	@echo done
