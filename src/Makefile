FLAGS=-Wall -O2

all: main.o game.o input.o version.o
	gcc $^ -o rock-paper-scissors

main.o: main.c
	gcc -c $^ $(FLAGS)
game.o: game.c
	gcc -c $^ $(FLAGS)
input.o: input.c
	gcc -c $^ $(FLAGS)
version.o: version.c
	gcc -c $^ $(FLAGS)

clean:
	rm *.o

.PHONY: all clean
