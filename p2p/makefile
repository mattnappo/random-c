SRC = src
BIN = bin/

CC = g++

SOURCE := $(shell find $(SRC) -name '*.cpp')
HEADERS = $(wildcard *.h)

main: $(SOURCE) $(HEADERS)
	$(CC) -o $(BIN)$@ $(SOURCE)
clean:
	rm -rf $(BIN)*