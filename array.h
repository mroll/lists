#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 16384

typedef double (^a_reduce_block)(void *);
typedef int (^a_filter_block)(void *);
typedef void* (^a_map_block)(void *);

extern double a_reduce(void *head, int nterms, int nsize, double (^rblock)(void *));
extern void a_filter(void *head, int nterms, int nsize, void **farray, int (^fblock)(void *));
extern void a_map(void *head, int nterms, size_t nsize, void **marray, void* (^mblock)(void *));
