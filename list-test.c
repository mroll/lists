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
	intlist *store;
	intlist *a = create(1);
	intlist *b = create(2);
	intlist *c = create(3);
	intlist *d = create(4);
	intlist *e = create(6);
	intlist *f = create(8);
	

	p = qpush(p, (node *)b);
	p = qpush(p, (node *)d);
	p = qpush(p, (node *)e);
	p = qpush(p, (node *)a);
	p = qpush(p, (node *)f);
	p = qpush(p, (node *)c);

	printf("list before delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	p = qpop(p, (node **)&store);
	printf("list after delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	printf("stored node: %d\n", store->data);
	p = qpop(p, (node **)&store);
	printf("list after delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	printf("stored node: %d\n", store->data);
	p = qpop(p, (node **)&store);
	printf("list after delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	printf("stored node: %d\n", store->data);
	p = qpop(p, (node **)&store);
	printf("list after delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	printf("stored node: %d\n", store->data);
	p = qpop(p, (node **)&store);
	printf("list after delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	printf("stored node: %d\n", store->data);
	p = qpop(p, (node **)&store);
	printf("list after delete: \n");
	list_iterate((node *)p, (list_iterate_callback)print_node_data);
	printf("stored node: %d\n", store->data);

	return 0;
}
