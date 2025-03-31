# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
OUTPUT_DIR = output
ifeq ($(OS),Windows_NT)
	RM = del /f
	TARGET = .\output\program.exe
else
	RM = rm -f
	TARGET = ./output/program
endif
SRC_DIR = src
TEST_DIR = tests
SRC = main.c $(SRC_DIR)/query.c $(SRC_DIR)/queryCollection.c dinamicArrayOps/$(SRC_DIR)/dinamicArray.c
TEST_SRC = $(TEST_DIR)\test.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

debug: $(SRC)
	$(CC) $(CFLAGS) -g $(SRC) -o $(TARGET)

clean:
	$(RM) $(TARGET)