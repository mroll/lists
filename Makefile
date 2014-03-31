CFLAGS = -g

list-test: list-test.c list.o
	$(CC) $(CFLAGS) list-test.c list.o -o list-test

list.o: list.c
	gcc $(CFLAGS) -c list.c

hash-test: hash-test.c hash.o
	gcc $(CFLAGS) hash-test.c hash.o list.o -o hash-test

hash.o: hash.c
	gcc $(CFLAGS) -c hash.c

dir-test: dir-test.c list.o hash.o
	gcc $(CFLAGS) -o dir-test dir-test.c hash.o list.o

tree-test: tree.c list.o
	$(CC) $(CFLAGS) -o tree-test tree.c list.o
