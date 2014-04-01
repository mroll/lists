#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _t_node {
	struct _t_node *left;
	struct _t_node *right;
	int data;
} t_node;

typedef struct _tnode_q_node {
	struct _tnode_q_node *next;
	t_node *tnode;
} tnode_q_node;

void print_tnode_q_node_data(tnode_q_node *head) {
	printf("%d ", head->tnode->data);
}

int t_node_cmp(t_node *a, t_node *b) {
	if (a->data < b->data) { return -1; }
	if (a->data > b->data) { return 1; }
	return 0;
}

t_node* tree_insert(t_node *root, t_node *new) {
	if (root == NULL) {
		root = new;
	} else {
		if ( t_node_cmp(root, new) == -1 ) { 
			root->right = tree_insert(root->right, new); 
		} else {
			root->left = tree_insert(root->left, new);
		}
	}

	return root;
}

int tree_depth(t_node *root) {
	int l_depth, r_depth;

	if (root == NULL) { return 0; }
	else {
		l_depth = tree_depth(root->left);
		r_depth = tree_depth(root->right);
	}

	if (l_depth > r_depth) { return l_depth + 1; } 
	else { return r_depth + 1; }
}

t_node* tree_search(t_node *root, t_node* target) {
	t_node *found;

	if (t_node_cmp(root, target) == 0) {
		found = target;
	} else {
		if (root->left != NULL) {
			found = tree_search(root->left, target);
		}
		if (root->right != NULL) {
			found = tree_search(root->right, target);
		} else {
				found = NULL;
		}
	}

	return found;
}

void print_tree(t_node *root) {
	if (root == NULL) {
		return;
	}

	if (root->left != NULL) {
		print_tree(root->left);
	}
	if (root->right != NULL) {
		print_tree(root->right);
	}

	printf("%d\n", root->data);
}

void bf_print(t_node *root) {
	if (root == NULL) {
		return;
	}

	tnode_q_node *q_ptr = NULL;
	tnode_q_node *q_item = malloc(sizeof(tnode_q_node));
	q_item->tnode = root;
	q_ptr = (tnode_q_node *)qpush((node *)q_ptr, (node *)q_item);

	while(q_ptr) {
		tnode_q_node *popped;
		q_ptr  = (tnode_q_node *)qpop((node *)q_ptr, (node **)&popped);

		printf("%d\n", popped->tnode->data);

		if(popped->tnode->left) {
			q_ptr = (tnode_q_node *)qpush((node *)q_ptr, (node *)popped->tnode->left);
			list_iterate((node *)q_ptr, (list_iterate_callback)print_tnode_q_node_data);
		}

		if(popped->tnode->right) {
			q_ptr = (tnode_q_node *)qpush((node *)q_ptr, (node *)popped->tnode->right);
			list_iterate((node *)q_ptr, (list_iterate_callback)print_tnode_q_node_data);
		}
	}
}

int main() {
	t_node *root = (t_node *)malloc(sizeof(t_node));
	t_node *b = (t_node *)malloc(sizeof(t_node));
	t_node *c = (t_node *)malloc(sizeof(t_node));
	t_node *d = (t_node *)malloc(sizeof(t_node));
	t_node *e = (t_node *)malloc(sizeof(t_node));
	t_node *f = (t_node *)malloc(sizeof(t_node));
	t_node *g = (t_node *)malloc(sizeof(t_node));
	t_node *h = (t_node *)malloc(sizeof(t_node));

	root = NULL;

	b->data = 10;
	c->data = 15;
	d->data = 12;
	e->data = 17;
	f->data = 3;
	g->data = 1;
	h->data = 7;

	root = tree_insert(root, b);
	root = tree_insert(root, c);
	root = tree_insert(root, d);
	root = tree_insert(root, e);
	root = tree_insert(root, f);
	root = tree_insert(root, g);
	root = tree_insert(root, h);

	print_tree(root);
	return 0;
}
