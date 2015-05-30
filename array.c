#include "array.h"
#include <stdio.h>

double a_reduce(void *head, int nterms, int nsize, double (^rblock)(void *)) {
    int a_len = nterms * nsize;
    double result = 0;

    int i;
    for (i=0; i<nterms; i++) {
        result += rblock(head + (i*nsize));
    }

    return result;
}

void a_filter(void *head, int nterms, int nsize, void **farray, int (^fblock)(void *)) {
    int i;
    for (i=0; i<nterms; i++) {
        if (fblock(head + (i*nsize))) {
            memcpy(*farray + (i*nsize), head + (i*nsize), nsize);
        }
    }
}

void a_map(void *head, int nterms, size_t nsize, void **marray, void* (^mblock)(void *)) {
    int i;
    for (i=0; i<nterms; i++) {
        void *mapped = mblock(head + (i*nsize));
        printf("mapped: %s\n", mapped);
        memcpy(*marray + (i*nsize), mapped, nsize);
    }
}
