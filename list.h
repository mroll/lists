typedef struct _node {
	struct _node *next;
} node;

typedef void (*list_iterate_callback)(node *);

typedef int (*list_node_cmp)(node *, node *);

extern node* list_insert(node *head, node *pos, node *new);

extern void list_delete(node *head);

extern node* list_search(node *head, node *target, list_node_cmp cmp);

extern node* node_delete(node *head, node *target, node **store) ;	//does not free deleted node. 

extern void list_iterate(node *head, void (*func)(node *) );

extern node* list_push(node *head, node *new);

extern node* list_pop(node **head);

extern node* qpush(node *head, node *new);

extern node* qpop(node *head, node **popped);

extern node* priority_insert(node *head, node *new);

//jenkins test comment2
//new jenkins test comment
