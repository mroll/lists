// CFLAGS = -g -fsanitize=undefined

plain: list-test.c array.c
	$(CC) $(CFLAGS) -g list-test.c array.c list.c -o list-test

list-test: list-test.c list.o
	$(CC) $(CFLAGS) list-test.c list.o -o list-test

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

hash-test: hash-test.c hash.o
	$(CC) $(CFLAGS) hash-test.c hash.o list.o -o hash-test

hash.o: hash.c
	$(CC) $(CFLAGS) -c hash.c

dir-test: dir-test.c list.o hash.o
	$(CC) $(CFLAGS) -o dir-test dir-test.c hash.o list.o

tree-test: tree.c list.o
	$(CC) $(CFLAGS) -o tree-test tree.c list.o
