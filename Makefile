
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c99 -O2 -Wall -Wextra -Iinclude

# Libraries
LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Output executable (root)
TARGET = game

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Default target
all: $(TARGET)

# Link executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDLIBS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run game
run: $(TARGET)
	./$(TARGET)

# Clean generated files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all run clean

