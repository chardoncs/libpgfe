include metadata.mak

.PHONY: all build rebuild clean test install uninstall init-scripts

all: 
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja -DCMAKE_TOOLCHAIN_FILE=$(DEFAULT_CMAKE_TOOLCHAIN_FILE)
	@cmake --build $(BUILD_DIR) --config Release -j20 --target all --
	@echo 'Building done'

rebuild: clean all

$(BUILD_DIR):
	@mkdir -vp $(BUILD_DIR)

clean:
	@echo -ne 'Cleaning... '
	@rm -rf ./$(BUILD_DIR)
	@echo 'done'

test: all
	@ctest --test-dir $(BUILD_DIR) -C Release

install: all
	@echo 'Installing headers...'
	@mkdir -vp $(HEADER_DIR) 
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

init-scripts:
	@chmod u+x ./scripts/{comment_header.py,update_meta.py,deploy.py}


# Cross compilation

build-x86_64: clean
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchains/x86_64-linux-gnu-clang.cmake
	@cmake --build $(BUILD_DIR) --config Release -j20 --target pgfe --
	@echo 'Building done'

build-x86_64-mold: clean
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchains/x86_64-linux-gnu-clang-mold.cmake
	@cmake --build $(BUILD_DIR) --config Release -j20 --target pgfe --
	@echo 'Building done'

build-aarch64-android: clean
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja \
		-DNDK_ROOT=$(NDK_ROOT) \
		-DCMAKE_TOOLCHAIN_FILE=./cmake/toolchains/aarch64-linux-android.cmake
	@cmake --build $(BUILD_DIR) --config Release -j20 --target pgfe --
	@echo 'Building done'

build-arm-android: clean
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchains/arm-linux-android.cmake \
		-DNDK_ROOT=$(NDK_ROOT)
	@cmake --build $(BUILD_DIR) --config Release -j20 --target pgfe --
	@echo 'Building done'

build-x86_64-android: clean
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchains/x86_64-linux-android.cmake \
		-DNDK_ROOT=$(NDK_ROOT)
	@cmake --build $(BUILD_DIR) --config Release -j20 --target pgfe --
	@echo 'Building done'

build-x86-android: clean
	@echo 'Building...'
	@cmake . -B $(BUILD_DIR) -G Ninja -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchains/x86-linux-android.cmake \
		-DNDK_ROOT=$(NDK_ROOT)
	@cmake --build $(BUILD_DIR) --config Release -j20 --target pgfe --
	@echo 'Building done'
