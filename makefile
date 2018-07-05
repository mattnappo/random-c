CC=gcc
tracker: camperTracker/tracker.c
	$(CC) -o build/tracker camperTracker/tracker.c -std=c99
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o build/linkedList pointers/updatedList.c pointers/listHeader.h -std=c99
classes: classes.cpp
	g++ -o build/classes classes.cpp