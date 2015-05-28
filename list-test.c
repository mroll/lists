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
    
    a = (intlist *) qpush((node *)a, (node *)b);
    a = (intlist *) qpush((node *)a, (node *)c);
    a = (intlist *) qpush((node *)a, (node *)d);
    a = (intlist *) qpush((node *)a, (node *)e);
    a = (intlist *) qpush((node *)a, (node *)f);

    a = (intlist *) reverse((node *) a);

    list_iterate((node *)a, (void *)print_node_data);

    return 0;
}
