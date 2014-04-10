#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hash.h"

//Jenkins test comment

typedef struct _fnode {
	struct _fnode *next;
	char *name;
	struct stat fstatus;
} fnode;

fnode* fnode_create(char *filename, struct stat fstatus) {
	fnode *new_node = (fnode *)malloc(sizeof(fnode));
	new_node->name = strdup(filename);
	(*new_node).fstatus = fstatus;

	return new_node;
}

void fnode_free(fnode *n) {
	printf("here1 %s\n", n->name);
	free(n->name);
	free(n);
	printf("here2\n");
}

typedef struct _intlist {
	node _n;
	int data;
}intlist;

void print_node_data(intlist *i) {
	printf("%d\n", i->data);
}

void print_fnode_data(fnode *n) {
	printf("%d %s ", fnode_hash(n), n->name);
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

int fnodecmp(fnode *a, fnode *b) {
	if(strcmp(a->name, b->name) < 0) {
		return -1;
	}
	else if(strcmp(a->name, b->name) > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
		

void hash_debug(HashTab *tab) {
	node *p;
	int i;

	printf("hashtab %p %d %d\n", tab, tab->width, tab->nsize);

	for(i=0; i<tab->width; i++) {
		printf("%d: ", i);
		list_iterate(tab->table[i], (list_iterate_callback)print_fnode_data);
		printf("\n");
	}
}

void hashtab_free(HashTab *t, void (*free)(node *)) {
	int i;

	for(i=0; i<t->width; i++) {
		list_iterate(t->table[i], (list_iterate_callback)free);
	}
}

int fnode_hash(fnode *n) {
	char *str = n->name;
	int result = *str;

	while(*str++) {
		result = result ^ *str++;
	}

	return result;
}

int inthash(intlist *n) {
	return n->data;
}

/**
int main() {
	HashTab *h = hashtab_init(50, sizeof(fnode), (hash_func)fnode_hash, (cmp_func)fnodecmp);
	fnode *a = (fnode *)malloc(sizeof(fnode));
	fnode *b = (fnode *)malloc(sizeof(fnode));
	fnode *c = (fnode *)malloc(sizeof(fnode));
	fnode *d = (fnode *)malloc(sizeof(fnode));

	a->name = "helloa";
	b->name = "hellob";
	c->name = "helloc";
	d->name = "hellod";

	hashtab_set(h, (node *)a);
	hashtab_set(h, (node *)b);
	hashtab_set(h, (node *)c);
	hashtab_set(h, (node *)d);
	hash_debug(h);

	return 0;
}
**/	
	

/**
int main() {
	DIR *dirp = opendir(".");
	struct dirent *dp = readdir(dirp);

	while(strcmp(dp->d_name, "find_start") != 0) {
		dp = readdir(dirp);
	}

	printf("%s\n", dp->d_name);

	return 0;
}


int main() {
	HashTab *table = hashtab_init(10, sizeof(fnode), (HashFunc)fnode_hash, (HashCmp)fnodecmp);
	node *x;
	int status, dirlen = strlen("/home/matt/code/C/testdir/");
	DIR *dirp = opendir("/home/matt/code/C/testdir/");
	struct dirent *dp;
	char *path_buf = (char *)malloc(sizeof(int) * 1024);
	strcpy(path_buf, "/home/matt/code/C/testdir/");

	while((dp = readdir(dirp))) {
		//dp = readdir(dirp);
		path_buf[dirlen] = '\0';
		strcat(path_buf, dp->d_name);
		fnode *n = (fnode *)malloc(sizeof(fnode));
		n->name = strdup(path_buf);

		if((status = stat(path_buf, &(n->fstatus))) != 0) {
			break;
		}
		//printf("%s\n", n->name);

		x = hashtab_set(table, (node *)n);
	}

	hash_debug(table);
	hashtab_free(table, (list_iterate_callback)fnode_free);

	return 0;
}
**/

int main() {
	int i;
	HashTab *table = hashtab_init(10, sizeof(fnode), (HashFunc)fnode_hash, (HashCmp)fnodecmp);
	fnode *a = (fnode *)malloc(sizeof(fnode));
	fnode *b = (fnode *)malloc(sizeof(fnode));
	fnode *c = (fnode *)malloc(sizeof(fnode));
	fnode *d = (fnode *)malloc(sizeof(fnode));

	a->name = strdup("helloa");
	b->name = strdup("hellob");
	c->name = strdup("helloc");
	d->name = strdup("hellod");
	stat("/home/matt/code/C/testdir/a", &(a->fstatus));
	stat("/home/matt/code/C/testdir/b", &(b->fstatus));
	stat("/home/matt/code/C/testdir/c", &(c->fstatus));
	stat("/home/matt/code/C/testdir/d", &(d->fstatus));
	hashtab_set(table, (node *)a);
	hashtab_set(table, (node *)b);
	hashtab_set(table, (node *)c);
	hashtab_set(table, (node *)d);

	hash_debug(table);
	hashtab_free(table, (list_iterate_callback)fnode_free);

	free(table->table);
	free(table);
	free(a);
	free(b);
	free(c);
	free(d);

	return 0;
}
