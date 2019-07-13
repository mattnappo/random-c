TARGET_EXEC ?= pow.out

BUILD_DIR ?= ./bin
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.c)
CC = gcc

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
FLAGS = -lpthread

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(FLAGS)
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)
MKDIR_P ?= mkdir -p