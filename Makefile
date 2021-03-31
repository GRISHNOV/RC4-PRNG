.PHONY: all clean

CC = gcc
CFLAGS = -c -Wall -Wextra -Wpedantic

all: buildProject
	
buildProject:	./build/RC4_PRNG.o ./build/RC4_PRNG_test.out

./build/RC4_PRNG.o:	./src/RC4_PRNG.c ./include/RC4_PRNG.h
	$(CC) $(CFLAGS) ./src/RC4_PRNG.c -o ./build/RC4_PRNG.o

./build/RC4_PRNG_test.o:	./test/RC4_PRNG_test.c ./test/RC4_PRNG_test.h ./include/RC4_PRNG.h
	$(CC) $(CFLAGS) ./test/RC4_PRNG_test.c -o ./build/RC4_PRNG_test.o

./build/RC4_PRNG_test.out:	./build/RC4_PRNG_test.o ./build/RC4_PRNG.o
	$(CC) ./build/RC4_PRNG_test.o ./build/RC4_PRNG.o -o ./build/RC4_PRNG_test.out

clean:
	rm -f ./build/*.o ./build/*.out