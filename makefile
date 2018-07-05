makeTracker: camperTracker/tracker.c
	gcc -o build/tracker camperTracker/tracker.c
makeList: pointers/updatedList.c pointers/listHeader.h
	gcc -o build/linkedList pointers/updatedList.c pointers/listHeader.h