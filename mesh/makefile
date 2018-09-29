SRC = src
BIN = bin/

SOURCE := $(shell find $(SRC) -name '*.cpp')
HEADERS = $(wildcard *.h)

mesh: $(SOURCE) $(HEADERS)
	g++ -o $(BIN)$@ $(SOURCE)
clean:
	rm -rf $(BIN)*