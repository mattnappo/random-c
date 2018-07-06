# CC=gcc-8
# CC=gcc
tracker: camperTracker/tracker.c
	$(CC) -o build/tracker.o camperTracker/tracker.c
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o build/linkedList.o pointers/updatedList.c pointers/listHeader.h
classes: classes.cpp
	$(CC) -o build/classes.o classes.cpp -lstdc++
all:
	make tracker
	make list
	make classes
clean:
	rm build/*.o
