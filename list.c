#include "list.h"


void l_delete(node *head) {
    node *p, *x;

    for(p=head; p != NULL; ) {
        x = p->next;
        free(p);
        p = x;
    }
}

node* l_insert(node *head, node *pos, node *new) {
    node *p, *prev = NULL;

    for(p=head; p != pos; p=p->next) {
        prev = p;
    }

    if (prev == NULL) {
        new->next = head;
        head = new;
        return head;
    }

    prev->next = new;
    new->next = p;

    return head;
}

/*node** l_insert(node **head, node *pos, node *new) {*/
    /*node *p, *prev = NULL;*/

    /*for(p=*head; p!=pos; p=p->next) {*/
        /*prev = p;*/
    /*}*/

    /*if(prev == NULL) {*/
        /*new->next = head;*/
        /*return new;*/
    /*}*/

    /*prev->next = new;*/
    /*new->next = pos;*/

    /**head = new;*/
    /*return head;*/
/*}*/


node* l_search(node *head, node *target, l_node_cmp cmp) {
    node *p;

    for(p=head; p!=NULL; p=p->next) {
        if(cmp(p, target) == 0) { break; }
    }

    return p;
}

node* node_delete(node *head, node *target, node **store) {        //does not free deleted node. 
    node *p, *prev = NULL;

    if(head == NULL) {
        return NULL;
    }

    if(head == target) {
        *store = head;
        p = head->next;
        head->next = NULL;
        return head;
    }

    if(head->next == NULL && target == NULL) {             //one item in queue
        *store = head;
        return NULL;
    }

    for(p=head; p->next!=target; p=p->next) {
        prev = p;
    }

    if(target == NULL) {
        if(*store != NULL) {
            printf("p->data: %p\n", p);
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


void l_iterate(node *head, void (*func)(node *) ) {
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

int len(node *head) {
    int nodes = 0;

    node *p = head;
    while (p) {
        nodes += 1;
        p = p->next;
    }

    return nodes;
}

node* l_push(node *head, node *new) {
    return l_insert(head, head, new);
}

node* l_pop(node *head) {
    node *tmp;
    tmp = head;
    head = node_delete(head, head, NULL);
    tmp->next = NULL;
    head = tmp;

    return head;
}

node* qpush(node *head, node *new) {
    return l_insert(head, head, new);
}

node* qpop(node *head, node **end) {
    return node_delete(head, NULL, end); 
}

node* l_reverse(node *head) {
    node *old_head = head, *tmp;

    node *np;
    while (old_head) {
        tmp = np;
        np = old_head;
        old_head = old_head->next;
        np->next = tmp;
    }

    return np;
}

node* l_filter(node *head, node* (*node_cpy)(node *), int (^fblock)(void *)) {
    node *current = head;
    node *newlist = NULL;
    node *tail = NULL;

    while (current != NULL) {
        if (fblock(current)) {
            if (newlist == NULL) {
                newlist = node_cpy(current);
                newlist->next = NULL;
                tail = newlist;
            } else {
                tail->next = node_cpy(current);
                tail = tail->next;
                tail->next = NULL;
            }
        }
        current = current->next;
    }

    return newlist;
}

double l_reduce(node *head, double (^rblock)(void *)) {
    double result = 0;

    node *np = head;
    while (np) {
        result += rblock((node *) np);
        np = np->next;
    }

    return result;
}

void* l_map(node *head, void* (^mblock)(void *)) {
    void *m_list;

    node *np = head;
    while (np) {
        node *mapped = mblock(np);
        l_insert(m_list, NULL, mapped);
        np = np->next;
    }

    return m_list;
}

void l_apply(node *head, void* (^ablock)(void *)) {
    node *np = head;
    node *tmp;
    while (np) {
        tmp = np->next;
        ablock(np);
        np = tmp;
    }
}
