CC=gcc
DEBUG=-g


run: main.o hash.o list.o
	$(CC) -o run main.o hash.o list.o $(DEBUG) && rm *.o && ./run

com: main.o hash.o
	$(CC) -o run main.o hash.o $(DEBUG) && rm *.o

main.o: main.c
	$(CC) -c main.c  $(DEBUG)

hash.o: src/hash_table.c
	$(CC) -c src/hash_table.c -o hash.o $(DEBUG)

list.o: src/g_list/list.c
	$(CC) -c src/g_list/list.c -o list.o $(DEBUG)

cl:
	rm *.o run
