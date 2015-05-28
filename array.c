#include "array.h"
#include <stdio.h>

double a_reduce(void *head[], int nterms, int nsize, double (^rblock)(void *)) {
    int a_len = nterms * nsize;
    double result = 0;

    int i;
    for (i=0; i<nterms; i++) {
        result += rblock(head[i*nsize]);
    }

    printf("result: %f\n", result);
    return result;
}

void* a_filter(void *head[], int nterms, int nsize, int (^fblock)(void *)) {
    int a_bytes = nsize * nterms;
    void *farray = (void *) malloc(MAX_ARRAY);

    int i;
    for (i=0; i<nterms; i++) {
        if (fblock(head[i*nsize])) {
            memcpy(&farray + (i*nsize), (void *) head[i*nsize], nsize);
        }
    }

    return farray;
}

void a_map(void *head[], int nterms, int nsize, void (^mblock)(void *)) {
    int a_len = nsize / nterms;
    int i;
    for (i=0; i<nterms; i++) {
        mblock(head[i*nsize]);
    }
}
