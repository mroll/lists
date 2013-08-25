typedef int (*hash_func)(node *);
typedef int (*cmp_func)(node *, node *);

typedef int (* HashFunc)(node *);
typedef int (* HashCmp)(node *a, node *b);

typedef struct _HashTab {
	int width;
	int nsize;
	HashCmp cmp;
	HashFunc hash;
	node** table;
} HashTab;

extern HashTab* hashtab_init(int width, int nsize, HashFunc hash, HashCmp cmp);

extern node* hashtab_set(HashTab *tab, node *n);

extern node* hashtab_get(HashTab *tab, node *n);

extern void hash_debug(HashTab *tab);
