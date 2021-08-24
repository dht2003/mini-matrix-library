CXX ?= g++
SRC_DIR = ./src
BUILD_DIR = ./build
BIN_DIR = $(BUILD_DIR)/bin
EXEC_NAME = matrix.out
TARGET = $(BIN_DIR)/$(EXEC_NAME)
IPATH = ./include


SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS :=  $(OBJS:.o=.d)

IDIR = $(shell find $(IPATH) -type d)
IFLAGS = $(addprefix -I,$(IDIR))

CXXFLAGS ?= $(IFLAGS) -Wall -Werror -Wextra -pedantic

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

$(TARGET) : $(OBJS) 
	@echo "Linking: $(OBJS)"
	$(CXX) $(OBJS) -o $@

-include $(DEPS)

.PHONY: clean
clean:
	@echo "Deleting executable $(TARGET)"
	@$(RM) $(TARGET)
	@echo "Deleting object files : $(OBJS)"
	@$(RM) $(OBJS)
	@echo "Deleting dependency files : $(DEPS)"
	@$(RM) $(DEPS)

.PHONY: dirs
dirs: 
	@echo "Creating build and bin directories"
	@mkdir -p $(dir $(OBJS))
	@mkdir -p $(BIN_DIR)