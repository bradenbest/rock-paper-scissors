FLAGS=-Wall -O2

all: main.o game.o
	gcc $^ -o rock-paper-scissors

main.o: main.c
	gcc -c $^ $(FLAGS)
game.o: game.c game.h
	gcc -c $^ $(FLAGS)

clean:
	rm *.o
	rm *.gch

.PHONY: all clean
