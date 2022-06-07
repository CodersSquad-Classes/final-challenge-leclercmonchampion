CC=gcc
CFLAGS=-Wall -Wextra -fopenmp

all:
	$(CC) $(CFLAGS) src/*.c main.c -o pacman.exe

adress:
	$(CC) $(CFLAGS) -fsanitize=address src/*.c main.c -o pacman.exe 

clean:
	rm -f pacman.exe

