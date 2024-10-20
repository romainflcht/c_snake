TARGET = main

# __ DIRECTORIES _______________________________________________________________
BUILD_DIR = build
INC_DIR   = include
SRCS_DIR  = src
OBJS_DIR  = objs

# __ FILES _____________________________________________________________________
SRCS = main.c console.c food.c input.c snake.c
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

# __ COMPILATION OPTIONS _______________________________________________________
CC      = gcc
C_FLAGS = -I$(INC_DIR) # -Wall -Wextra -Werror
L_LIBS  = -lncurses

# __ RULES _____________________________________________________________________
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS) | mkdir_build
	$(CC) -o $(BUILD_DIR)/$(TARGET) $(OBJS) $(L_LIBS) $(C_FLAGS)


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | mkdir_objs
	@echo "-> COMPILING $@ USING $<"
	@$(CC) -c $< -o $@ $(C_FLAGS)

$(OBJS_DIR)/$(TARGET).o: $(TARGET).c | mkdir_objs
	@echo "-> COMPILING $@ USING $<"
	@$(CC) -c $< -o $@ $(C_FLAGS)


run: $(BUILD_DIR)/$(TARGET)
	@clear
	./$(BUILD_DIR)/$(TARGET)

clean:
	@echo "CLEANING DIRECTORY"
	@rm -rf $(OBJS_DIR) $(BUILD_DIR)/$(TARGET)

mkdir_objs: 
	@mkdir -p $(OBJS_DIR)

    
mkdir_build: 
	@mkdir -p $(BUILD_DIR)

.PHONY: all run clean mkdir_objs mkdir_build