game: horse.o track.o main.o track.o
	g++ -g horse.o track.o main.o -o game

horse.o: horse.cpp
	g++ -c -g horse.cpp

track.o: horse.h track.cpp
	g++ -c -g track.cpp

main.o: horse.h track.h main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o
	rm game

run: game
	./game

debug: game
	gdb game
