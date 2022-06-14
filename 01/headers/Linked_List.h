#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stddef.h>
#include <sys/cdefs.h>

typedef struct Node
{
	int data;
	struct Node *link;
} node_t;

typedef node_t *LinkedListPtr;

__BEGIN_DECLS

extern void initialize(void);
extern LinkedListPtr create_node(int);

extern void add_to_beg(void);
extern void add_to_end(void);
extern void add_at_pos(void);

extern void del_first(void);
extern void del_last(void);
extern void del_pos(void);
extern void del_list(void);

extern void update(void);
extern int count_of_nodes(void);
extern void search(void);
extern void reverse(void);
extern int is_empty(LinkedListPtr);
extern void display(void);

__END_DECLS

#endif	/* LINKEDLIST_H_INCLUDED */
