#include <stdio.h>
#include <stdlib.h>
#include "list.h" 
#include "array.h"

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

intlist* intlist_cpy(intlist *src) {
    intlist *new = (intlist *) malloc(sizeof(intlist));
    new->data = src->data;

    return new;
}

int main() {
    /*intlist **tmp;*/
    /*node *p = NULL;*/
    /*intlist *store;*/

    /*intlist *a = create(1);*/
    /*intlist *b = create(2);*/
    /*intlist *c = create(3);*/
    /*intlist *d = create(4);*/
    /*intlist *e = create(6);*/
    /*intlist *f = create(8);*/
    
    /*a = (intlist *) l_insert((node *)a, NULL, (node *)b);*/
    /*a = (intlist *) l_insert((node *)a, NULL, (node *)c);*/
    /*a = (intlist *) l_insert((node *)a, NULL, (node *)d);*/
    /*tmp = (intlist **) qpush((node **)a, (node *)e);*/
    /*tmp = (intlist **) qpush((node **)a, (node *)f);*/

    // tmp = (intlist **) l_reverse((node **) a);


    // intlist *filtered;
    /*double r = l_reduce((node *)a, ^(void *i) {*/
            /*double ret = ((intlist *) i)->data + 10;*/
            /*return ret;*/
                /*});*/
    //print_node_data(filtered);
    /*filtered = (intlist *) l_filter((node *)a, (void *) intlist_cpy, ^(void *i) {*/
            /*if (((intlist *)i)->data < 3) { return 1; }*/
            /*else { return 0; }*/
                /*});*/

    /*l_iterate((node *)filtered, (void *) print_node_data);*/
    /*printf("\n");*/
    /*l_iterate((node *)filtered, (void *) print_node_data);*/


    // l_delete((node *)tmp);
    /*printf("here\n");*/
    // print_node_data((intlist *) a->_n.next);

    /*l_map((node **)tmp, ^(void *n) {*/
                /*print_node_data((intlist *) n);*/
                /*});*/

    typedef double (^a_reduce_block)(void *);
    typedef int (^a_filter_block)(void *);
    typedef void* (^a_map_block)(void *);
    int mod = 10;
    int a[5] = { 1, 2, 3, 4, 5 };

    int (^mblock)(int *) = ^int (int *el) {
        int mapped;
        mapped = *el * mod;
        return mapped;
    };
    int *m_a = (int *) calloc(1, 5 * sizeof(int));;
    a_map(a, 5, sizeof(int), (void **) &m_a, (a_map_block) mblock);

    /*printf("m_a[0]: %d\n", m_a[0]);*/
    /*printf("m_a[1]: %d\n", m_a[1]);*/
    /*printf("m_a[2]: %d\n", m_a[2]);*/


    /*free(m_a);*/
    /*double (^rblock)(int*) = ^double (int *el) {*/
        /*return *el + mod;*/
    /*};*/

    int *f_a = (int *) calloc(1, 5 * sizeof(int));
    int (^fblock)(int *) = ^int (int *el) {
        return *el < 3;
    };
    a_filter(a, 5, sizeof(int), (void **) &f_a, (a_filter_block) fblock);

    printf("a[0]: %d\n", a[0]);
    printf("a[1]: %d\n", a[1]);
    printf("a[2]: %d\n", a[2]);
    printf("\n");
    printf("f_a[0]: %d\n", f_a[0]);
    printf("f_a[1]: %d\n", f_a[1]);
    printf("f_a[2]: %d\n", f_a[2]);

    free(f_a);

    /*double r = a_reduce(a, 5, sizeof(int), (a_reduce_block) rblock);*/
    /*printf("r: %f\n", r);*/

    

    return 0;
}
