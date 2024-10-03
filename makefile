APP_NAME := main

BUILD_DIR := build
INC_DIR := include
SRC_DIR := src

SOURCES := $(wildcard $(SRC_DIR)/*.c) main.c

C_FLAGS := -Wall -Werror -Wextra
L_LIBS := -lncurses

all: 
	@echo "LISTING ALL SOURCE FILE FOUND : " $(SOURCES) "\n\n"
	gcc $(SOURCES) -o $(BUILD_DIR)/$(APP_NAME).out -I$(INC_DIR) $(C_FLAGS) $(L_LIBS) 

run: all
	clear
	./$(BUILD_DIR)/$(APP_NAME).out