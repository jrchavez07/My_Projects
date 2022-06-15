#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "Linked_List.h"
#include "read_int.h"

LinkedListPtr head;

void
initialize(void)
{
	head = NULL;
	return;
}


LinkedListPtr
create_node(int digit)
{
	LinkedListPtr temp = NULL;

	temp = (node_t *)malloc(sizeof(node_t));
	if (is_empty(temp)) {
		(void)fprintf(stderr, "%s\n", strerror(ENOMEM));
		exit(EXIT_FAILURE);
	} else {
		temp->data = digit;
		temp->link = NULL;
	}
	return (temp);
}


void
add_to_beg(void)
{
	auto int digit = 0;

	printf("read an integer value: ");
	read_int(&digit);
	
	LinkedListPtr temp = create_node(digit);

	temp->link = head;
	head = temp;
	return;
}


void
add_to_end(void)
{

	auto int digit = 0;
	
	printf("read an integer value: ");
	read_int(&digit);

	LinkedListPtr ptr = head;
	LinkedListPtr temp = create_node(digit);
	
	while (!is_empty(ptr->link))
		ptr = ptr->link;
	ptr->link = temp;
	return;
}


void
add_at_pos(void)
{
	auto int digit = 0;
	auto int pos = 0;

	printf("read an integer value: ");
	read_int(&digit);

	printf("enter position: ");
	read_int(&pos);

	LinkedListPtr ptr = head;
	LinkedListPtr temp = create_node(digit);

	pos--;
	while (pos != 1) {
		ptr = ptr->link;	
		pos--;
	}
	temp->link = ptr->link;
	ptr->link = temp;
	return;
}


void
del_first(void)
{
	if (is_empty(head))
		printf("List Linked is already empty.\n");
	else {
		LinkedListPtr temp = head;
		head = head->link;
		free(temp);
		temp = NULL;
	}
	return;
}


void
del_last(void)
{
	if (is_empty(head))
		printf("List is already empty.\n");
		
	else if (is_empty(head->link)) {
		free(head);
		head = NULL;
	} else {
			
		LinkedListPtr temp = head;

		while (temp->link->link != NULL) {
			temp = temp->link;
		}

		free(temp->link);
		temp->link = NULL;
	}
	return;
}


void
del_pos(void)
{
	auto int pos = 0;
	LinkedListPtr current = head;
	LinkedListPtr previous = head;

	printf("enter position: ");
	read_int(&pos);

	if (is_empty(head)) {
		(void)fprintf(stdout, "List is already empty.\n");
	} else if (pos == 1) {
		head = current->link;
		free(current);
		current = NULL;
	} else {
		while (pos != 1) {
			previous = current;
			current = previous->link;
			pos--;
		}
		previous->link = current->link;
		free(current);
		current = NULL;
	}
	return;
}


void
del_list(void)
{
	LinkedListPtr temp = head;

	while (!is_empty(temp)) {
		temp = temp->link;
		free(head);
		head = temp;
	}

	if (is_empty(head))
		(void)fprintf(stdout, "the list has been deleted successfully.\n");
	return;
}


void
update(void)
{
	auto int old_digit = 0, new_digit = 0, inc = 0;
	_Bool found = false;

	if (is_empty(head))
		(void)fprintf(stdout, "List is empty.\n");

	printf("read an integer value: ");
	read_int(&old_digit);

	printf("read a new integer value: ");
	read_int(&new_digit);

	int size = count_of_nodes();
	LinkedListPtr ptr = NULL;
	ptr = head;

	while (!found && inc < size) {
			
		if (ptr->data == old_digit) {
			ptr->data = new_digit;
			found = true;
		} else {
		}
		ptr = ptr->link;
	}

	if (found)
		printf("the element has been successfully updated.\n");
	else
		printf("element: %d not found in list.\n", new_digit);
	return;
}


int
count_of_nodes(void)
{
	auto int count = 0;

	if (is_empty(head))
		(void)fprintf(stdout, "List is empty.\n\n");
	
	LinkedListPtr ptr = NULL;

	ptr = head;
	while (!is_empty(ptr)) {
		count++;
		ptr = ptr->link;
	}
	return (count);
}


void
search(void)
{
	auto int digit = 0, inc = 0, pos = 0;
	_Bool found = false;

	printf("read an integer value: ");
	read_int(&digit);

	int size = count_of_nodes();
	LinkedListPtr ptr = NULL;
	ptr = head;

	while (!found && inc < size) {
		
		if (ptr->data == digit)
			found = true;
		else
			inc++;
		ptr = ptr->link;
	}

	pos = inc + 1;
	if (found)
		printf("element: %d found at: %d position.\n", digit, pos);
	else
		printf("element: %d not found in list.\n", digit);
	return;
}


void
reverse(void)
{
	LinkedListPtr prev = NULL;
	LinkedListPtr next = NULL;

	 while (!is_empty(head)) {
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	 }
	 head = prev;
	 return;
}


int
is_empty(LinkedListPtr ptr)
{
	return (ptr == NULL);
}


void
display(void)
{
	if (is_empty(head))
		(void)fprintf(stdout, "Linked List is empty.\n");
	else {
		LinkedListPtr ptr = head;

		while (!is_empty(ptr)) {
			printf("%d ---> ", ptr->data);
			ptr = ptr->link;
		}
		putchar('\n');
	}
	return;
}
