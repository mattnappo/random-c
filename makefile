# CC=gcc-8
CC=gcc
tracker: camperTracker/tracker.c
<<<<<<< HEAD
	$(CC) -o build/tracker camperTracker/tracker.c -std=c99
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o build/linkedList pointers/updatedList.c pointers/listHeader.h -std=c99
classes: classes.cpp
	g++ -o build/classes classes.cpp
=======
	$(CC) -o build/tracker.o camperTracker/tracker.c -std=c99
list: pointers/updatedList.c pointers/listHeader.h
	$(CC) -o build/linkedList.o pointers/updatedList.c pointers/listHeader.h -std=c99
classes: classes.cpp
	$(CC) -o build/classes.o classes.cpp -lstdc++
>>>>>>> 332027e75cb585b3f315518a1a713734fdce8694
all:
	make tracker
	make list
	make classes
clean:
<<<<<<< HEAD
	rm build/*
=======
	rm build/*.o
	rm build/*.exe
>>>>>>> 332027e75cb585b3f315518a1a713734fdce8694
