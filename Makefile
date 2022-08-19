include meta.mak

all: clean $(TARGET)
	@echo 'All done'

$(TARGET): $(OBJS) $(LIBS)
	@echo 'Linking...'
	$(CC) -shared $(OUTPUT_OPTION) $^

$(OBJS): $(BUILD_DIR)

$(OBJS_DIR)/%.c.o: %.c
	$(CC) -c $(OUTPUT_OPTION) $< $(STD_OPTION)

$(OBJS_DIR)/%.cpp.o: %.cpp
	$(CPP) -c $(OUTPUT_OPTION) $< $(STD_CPP_OPTION)

$(BUILD_DIR):
	@mkdir -v $(BUILD_DIR)
	@mkdir -vp $(OBJS_DIR)
	@mkdir -vp $(TARGET_DIR)

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

update-meta:
	@python3 ./scripts/update_meta.py ./project.json
