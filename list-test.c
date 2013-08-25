#include <stdio.h>
#include <stdlib.h>
#include "list.h" 

typedef struct _intlist {
	node _n;
	int data;
}intlist;

intlist* create(int val) {
	intlist *newp = (intlist *)calloc(1, sizeof(intlist));
	newp->data = val;

	return newp;
}

void print_node_data(intlist *i) {
	printf("%d\n", i->data);
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


int main() {
	intlist **tmp;
	node *p = NULL;
	intlist *test;
	intlist *a = create(1);
	intlist *b = create(2);
	intlist *c = create(3);
	intlist *d = create(4);
	intlist *e = create(6);
	intlist *f = create(8);
	

	p = priority_insert(p, (node *)b);
	p = priority_insert(p, (node *)d);
	p = priority_insert(p, (node *)e);
	p = priority_insert(p, (node *)a);
	p = priority_insert(p, (node *)f);
	p = priority_insert(p, (node *)c);
	//p = delete(p, (node *)f, NULL);

	test = (intlist *)list_search(p, (node *)b, (list_node_cmp)nodecmp);
	printf("%d\n", test->data);
	//iterate((node *)p, (iterate_callback)print_node_data);

	return 0;
}
