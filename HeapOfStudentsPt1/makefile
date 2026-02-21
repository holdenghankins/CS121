program: address.o date.o name.o student.o main.o
	g++ -g address.o date.o name.o student.o main.o -o program

address.o: address.cpp
	g++ -c -g address.cpp

date.o: date.cpp
	g++ -c -g date.cpp

name.o: name.cpp
	g++ -c -g name.cpp

student.o: address.h date.h name.h student.cpp
	g++ -c -g student.cpp

main: address.o date.o name.o student.o main.cpp
	g++ -g 

clean:
	rm *.o
	rm program

run: program
	./program

debug: program
	gdb program