# Output directory for building
BUILD_DIR = build

# Project name or target executable file
TARGET = boost_tcp_client

# Default rule for initialization and building
all: $(BUILD_DIR)/Makefile
	make -C $(BUILD_DIR)

# Rule for creating the build directory and running CMake
$(BUILD_DIR)/Makefile: CMakeLists.txt
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

# Rule for running the executable file
run: all
	$(BUILD_DIR)/$(TARGET)

# Rule for cleaning generated files
clean:
	@rm -rf $(BUILD_DIR)

# PHONY targets (do not interact with files)
.PHONY: all clean run
