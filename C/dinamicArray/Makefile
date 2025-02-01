# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
ifeq ($(OS),Windows_NT)
	RM = del /f
	TARGET = sum.exe
	TEST_TARGET = test_sum.exe
else
	RM = rm -f
	TARGET = sum
	TEST_TARGET = test_sum
endif
SRC_DIR = src
TEST_DIR = tests
SRC = main.c $(SRC_DIR)/sum.c
TEST_SRC = $(TEST_DIR)/test_sum.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

test: $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRC)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRC)

clean:
	$(RM) $(TARGET) $(TEST_TARGET)