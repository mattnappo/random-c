CC=gcc
build/tracker: camperTracker/tracker.c
	$(CC) -o tracker camperTracker/tracker.c -std=c99
	
build/list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o linkedList pointers/updatedList.c pointers/listHeader.h -std=c99
build/classes: classes.cpp
	g++ -o classes classes.cpp