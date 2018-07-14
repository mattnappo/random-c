CC=gcc
tracker: pointers/tracker.c
	$(CC) pointers/tracker.c -std=c99
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) pointers/updatedList.c pointers/listHeader.h -std=c99

all:
	make tracker
	make list
clean:
	rm build/*.o
	rm build/*.exe
