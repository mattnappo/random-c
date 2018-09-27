SRC = src
BIN = bin/

SOURCE := $(shell find $(SRC) -name '*.c')
HEADERS = $(wildcard *.h)

mesh: $(SOURCE) $(HEADERS)
	gcc -o $(BIN)$@ $(SOURCE)
clean:
	rm -rf $(BIN)*