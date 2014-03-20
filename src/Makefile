OBJS=main.o
FLAGS=-Wall -O2

all: $(OBJS)
	gcc $^ -o rock-paper-scissors

main.o: main.c
	gcc -c main.c $(FLAGS)

clean:
	rm $(OBJS)

.PHONY: all clean
