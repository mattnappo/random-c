# CC=gcc-8
CC=gcc
tracker: camperTracker/tracker.c
	$(CC) pointers/tracker.c -std=c99
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o build/linkedList pointers/updatedList.c pointers/listHeader.h -std=c99
classes: classes.cpp
	g++ -o build/classes classes.cpp
	$(CC) -o build/tracker.o pointers/tracker.c -std=c99
all:
	make tracker
	make list
	make classes
clean:
	rm build/*.o
	rm build/*.exe
