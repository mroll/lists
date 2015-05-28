#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 16384

extern double a_reduce(void *head[], int nterms, int nsize, double (^rblock)(void *));
extern void* a_filter(void *head[], int nterms, int nsize, int (^fblock)(void *));
extern void a_map(void *head[], int nterms, int nsize, void (^mblock)(void *));
