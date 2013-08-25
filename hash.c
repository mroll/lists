#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hash.h"

HashTab* hashtab_init(int width, int nsize, HashFunc hash, HashCmp cmp) {
	HashTab *tab = (HashTab *)malloc(sizeof(HashTab));
	tab->width = width;
	tab->table = (node **)malloc(width * sizeof(node *));
	tab->nsize = nsize;
	tab->hash = hash;
	tab->cmp = cmp;
	return tab;
}

node* hashtab_set(HashTab *tab, node *n) {
	node *found;
	int h = tab->hash(n) % tab->width;
	printf("%p %d\n", n, h);

	if( (found = list_search(tab->table[h], n, tab->cmp)) != NULL)  {
		memcpy(found, n, tab->nsize);
	} else {
		found = (node *)malloc(tab->nsize);
		memcpy(found, n, tab->nsize);
		tab->table[h] = list_insert(tab->table[h], NULL, (node *)found);
	}

	return found;
}	

node* hashtab_get(HashTab *tab, node *n) {
	int h = tab->hash(n) % tab->width;
	
	return list_search(tab->table[h], n, tab->cmp); 
}

