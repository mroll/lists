#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void list_delete(node *head) {
	node *p, *x;

	for(p=head; p != NULL; ) {
		x = p->next;
		free(p);
		p = x;
	}
}

node* list_insert(node *head, node *pos, node *new) {
	node *p, *prev = NULL;

	for(p=head; p != pos; p=p->next) {
		prev = p;
	}

	if(prev == NULL) {
		new->next = head;
		return new;
	}

	prev->next = new;
	new->next = pos;
	return head;
}


node* list_search(node *head, node *target, list_node_cmp cmp) {
	node *p;

	for(p=head; p!=NULL; p=p->next) {
		if(cmp(p, target) == 0) { break; }
	}

	return p;
}

node* node_delete(node *head, node *target, node **store) {		//does not free deleted node. 
	node *p, *prev = NULL;

	if(head == NULL) {
		return NULL;
	}

	if(head == target) {
		*store = head;
		p = head->next;
		head->next = NULL;
		return p;
	}

	if(head->next == NULL && target == NULL) { 			//one item in queue
		*store = head;
		return NULL;
	}

	for(p=head; p->next!=target; p=p->next) {
		prev = p;
	}

	if(target == NULL) {
		if(*store != NULL) {
			*store = p;
		}
		prev->next = NULL;
		return head;
	} else {
			if(*store != NULL) {
				*store = p;
			}
		p->next = p->next->next;
	}

	if(prev->next == NULL) {
		*store = head;
	}

	//free(p);
	return head;
}


void list_iterate(node *head, void (*func)(node *) ) {
	node *p, *tmp;

	p = head;
	while(p!=NULL) {
		tmp = p->next;
		func(p);
		p = tmp;
	}
	/**
	for(p=head; p!=NULL; p=p->next) {
		func(p);
	}
**/
}

node* list_push(node *head, node *new) {
	return list_insert(head, head, new);
}

node* list_pop(node **head) {
	node *tmp;
	tmp = *head;
	*head = node_delete(*head, *head, NULL);
	tmp->next = NULL;
	return tmp;
}

node* qpush(node *head, node *new) {
	return list_insert(head, head, new);
}

node* qpop(node *head, node **end) {
	return node_delete(head, NULL, end); 
}

/**
node* priority_insert(node *head, node *new) {
	node *p = head;

	while(p!=NULL && nodecmp(new, p) >= 0) {
		p = p->next;
	}

	head = list_insert(head, p, new);
	return head;
}
**/
		

/**-------------------------------------------------------------------------------**/
/**-------------------------------------------------------------------------------**/

//stack api
//queue api
//priority queue api w/ insert func taking pointer to cmparison
//comparison func takes pointer to a and b and returns int(-1, 0, 1)


