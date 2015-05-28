#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hash.h"

typedef struct _intlist {
	node _n;
	int data;
} intlist;

void hashtab_free(HashTab *t, void (*free)(node *)) {
	int i;

	for(i=0; i<t->width; i++) {
		list_iterate(t->table[i], (list_iterate_callback)free);
	}
}

int inthash(intlist *n) {
	return n->data;
}

int intcmp(intlist *a, intlist *b) {
	if(a->data < b->data) { return -1; }	
	if(a->data > b->data) { return 1; }	
	return 0;
}	

intlist* create(int val) {
	intlist *newp = (intlist *)calloc(1, sizeof(intlist));
	newp->data = val;

	return newp;
}

void print_node_data(intlist *i) {
	printf("%d ", i->data);
}

void hash_debug(HashTab *tab) {
	node *p;
	int i;

	printf("hashtab %p %d %d\n", tab, tab->width, tab->nsize);

	for(i=0; i<tab->width; i++) {
		printf("%d: ", i);
		list_iterate(tab->table[i], (list_iterate_callback)print_node_data);
		printf("\n");
	}
}

int nodecmp(intlist *a, intlist *b) {
	if(a->data < b->data) {
		return -1;
	}
	else if(a->data > b->data) {
		return 1;
	}
	else {
		return 0;
	}
}

void intlist_free(intlist *i) {
	free(i);
}

int main() {
	intlist *a = create(1);
	intlist *b = create(2);
	intlist *c = create(3);
	intlist *d = create(11);
	intlist *e = create(110);
	intlist *f = create(21);
	HashTab *htable = hashtab_init(10, sizeof(intlist), (hash_func)inthash, (cmp_func)intcmp);
	
	hashtab_set(htable, (node *)a);
	hashtab_set(htable, (node *)b);
	hashtab_set(htable, (node *)c);
	hashtab_set(htable, (node *)d);
	hashtab_set(htable, (node *)e);
	hashtab_set(htable, (node *)f);
    hash_debug(htable);

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	free(htable);
	
	return 0;
}	
