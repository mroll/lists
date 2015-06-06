#include "array.h"
#include <stdio.h>
#include <pthread.h>

double a_reduce(void *head, int nterms, int nsize, double (^rblock)(void *)) {
    double result = 0;
    pthread_t *threads = (pthread_t *) malloc(nterms * sizeof(pthread_t));

    int i;
    /*printf("head: %s\n", (char *)head);*/
    for (i=0; i<nterms; i++) {
        result += rblock(*((void **) head + i));
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

void* a_map(void *head, int nterms, size_t nsize, void* (^mblock)(void *)) {
    void *marray = malloc(nterms * nsize);

    int i;
    for (i=0; i<nterms; i++) {
        void *mapped = mblock(head + (i * nsize));
        memcpy(marray + (i * nsize), mapped, sizeof(mapped));
    }

    return marray;
}

void a_apply(void *head, int nterms, size_t nsize, void* (^ablock)(void *)) {
    int i;
    for (i=0; i<nterms; i++) {
        // printf("head[i*nsize]: %s\n", head + i);
        ablock(*((void **) head + i));
    }
}
