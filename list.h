#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _node {
	struct _node *next;
} node;

#define MAX_NODES 8192

typedef void (*l_iterate_callback)(node *);
typedef int (*l_node_cmp)(node *, node *);
extern node* l_insert(node *head, node *pos, node *new);
extern void l_delete(node *head);
extern node* l_search(node *head, node *target, l_node_cmp cmp);
extern node* node_delete(node *head, node *target, node **store) ;	//does not free deleted node. 
extern void l_iterate(node *head, void (*func)(node *) );
extern node* l_push(node *head, node *new);
extern node* l_pop(node **head);
extern node* qpush(node *head, node *new);
extern node* qpop(node *head, node **popped);
extern node* priority_insert(node *head, node *new);
extern node* l_reverse(node *head);
extern int len(node *head);
extern node* l_filter(node *head, int (^fblock)(void *));
extern double l_reduce(node *head, double (^rblock)(void *));
extern void l_map(node *head, void (^mblock)(void *));
