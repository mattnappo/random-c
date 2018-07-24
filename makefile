CC=gcc
tracker: pointers/tracker.c
	$(CC) pointers/tracker.c -std=c99
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) pointers/updatedList.c pointers/listHeader.h -std=c99
bogo: bogo.cpp
	g++ bogo.cpp -o bogo
all:
	make tracker
	make list
	make bogo
clean:
	rm *.o
	rm *.exe
	rm build/*.o
	rm build/*.exe
