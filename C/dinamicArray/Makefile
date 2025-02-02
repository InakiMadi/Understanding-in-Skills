# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
OUTPUT_DIR = output
ifeq ($(OS),Windows_NT)
	RM = del /f
	TARGET = .\output\main.exe
else
	RM = rm -f
	TARGET = ./output/main
endif
SRC_DIR = src
TEST_DIR = tests
SRC = main.c $(SRC_DIR)/dinamicArray.c
TEST_SRC = $(TEST_DIR)/test.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	$(RM) $(TARGET)