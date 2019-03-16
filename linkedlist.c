#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/* reference solution provided with assignment description */
void ll_show(ll_node *list) {
    ll_node *ptr = ll_head(list);
    putchar('[');
    while(ptr) {
        if (ptr->prev) printf(", ");
        if (ptr == list) putchar('*');
        printf("%d", ptr->value);
        if (ptr == list) putchar('*');
        ptr = ptr->next;
    }
    puts("]");
}

/**
 * Returns a pointer to the first node of a list, given a pointer to any node
 * in the list. If the provided pointer is `NULL`, instead returns `NULL`.
 */
ll_node *ll_head(ll_node *list) {
	if(!list) {
		return NULL;
	}
	ll_node *curNode = list;
	while(curNode->prev != NULL) {
		curNode = curNode->prev;
	}
	return curNode;
}


/**
 * Returns a pointer to the last node of a list, given a pointer to any node
 * in the list. If the provided pointer is `NULL`, instead returns `NULL`.
 */
ll_node *ll_tail(ll_node *list) {
	if(!list) {
			return NULL;
	}
	ll_node *curNode = list;
	while(curNode->next != NULL) {
		curNode = curNode->next;
	}
	return curNode;

}

/**
 * Returns the number of nodes in the list, which is the same for all nodes
 * in the list and 0 for `NULL`.
 */
unsigned long ll_length(ll_node *list) {
	if(!list) {
		return 0;
	}
	ll_node *ptr = ll_head(list);
	int count = 1;
	while(ptr->next != NULL) {
		ptr = ptr->next;
		count ++;
	}

	return count;
}

/**
 * Given a pointer to a node in a list, returns a pointer to the first node
 * at or after that node which has the given `value`. If given `NULL`, or
 * if no such node exists, returns `NULL`.
 */
ll_node *ll_find(ll_node *list, int value) {
	if(!list) {
		return NULL;
	}

	ll_node *curNode = list;
	if(curNode->value == value) {
		return list;
	}
	else {
		while(curNode->next != NULL) {
			curNode = curNode->next;
			if(curNode->value == value) {
				return curNode;
			}
		}
	}
	return NULL;
}

/**
 * Given a pointer to a node in a list, remove that node from the list,
 * `free`ing its memory in the process. Returns a pointer to the node that now
 * occupies the same position in the list that the removed node used to occupy
 * (which may be `NULL` if the removed node was the last node in the list).
 *
 * If given `NULL`, this function does nothing and returns `NULL`.
 */
ll_node *ll_remove(ll_node *list) {
	if(!list) {
		return NULL;
	}
	//Add Corner case if there is only one node

	ll_node *newCurNode = list->next;
	ll_node *prevNode = list->prev;
	prevNode->next = newCurNode;
	free(list);
	return newCurNode;

}

/**
 * Extend a list by one by adding `value` next to `list`. If `before` is 0,
 * inserts `value` immediately following the node pointed to by `list`;
 * otherwise inserts `value` immediately before that node. If `list` is NULL,
 * the newly inserted node is the entire list. In all cases, the new node is
 * allocated using `malloc` and returned by the function.
 */
ll_node *ll_insert(int value, ll_node *list, int before) {
	if(!list) {
        ll_node *newNode = malloc(sizeof(ll_node));
        list = newNode;
		list->value = value;
		list->next = NULL;
		list->prev = NULL;
		return list;
	}
	ll_node *newNode = malloc(sizeof(ll_node));

	if(before == 0) {
		newNode->value = value;
		newNode->next = list->next;
		newNode->prev = list;
		if(list->next != NULL) {
            list->next->prev = newNode;
        }
        list->next = newNode;
	}
	else {
        newNode->value = value;
        newNode->next = list;
        newNode->prev = list->prev;
        if (list->prev != NULL) {
            list->prev->next = newNode;
        }
		list->prev = newNode;
	}
	return newNode;
}