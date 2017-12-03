trains: main.o test.o
	g++ -o trains main.o test.o
main.o: main.cpp test.h
	g++ -c main.cpp
test.o: test.cpp test.h
	g++ -c test.cpp
clean:
	\rm *.o *~ pl
