CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
OBJ = main.o operacoes.o
DEPS = operacoes.h
VFLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes
EXEC = ./exec

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o exec

valgrind:
	valgrind $(VFLAGS) $(EXEC)
run:
	$(EXEC)
