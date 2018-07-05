CC=gcc
tracker: camperTracker/tracker.c
	$(CC) -o build/tracker camperTracker/tracker.c
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o build/linkedList pointers/updatedList.c pointers/listHeader.h
classes: classes.cpp
	g++ -o build/classes classes.cpp