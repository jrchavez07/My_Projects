#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <err.h>

#include "headers/Linked_List.h"
#include "headers/read_int.h"

static void menu(void);

int
main(void)
{
	auto int ch = 0;
	_Bool flags = false;

	menu();
	initialize();
	do {
		printf("::? ");
		read_int(&ch);

		switch (ch) {
		case 1:
			printf(
					"	1. to add an element at beginning of the list.\n"
					"	2. to add an element at the end of the list.\n"
					"	3. to add an element to a specific position.\n"
			      );
			printf("::? ");
			read_int(&ch);
			
			switch (ch) {
			case 1:
				add_to_beg();
				break;
			case 2:
				add_to_end();
				break;
			case 3:
				add_at_pos();
				break;
			default:
				break;
			}
			break;
		case 2:
			printf(
				"	1. to delete an element from the beginning of the list.\n"
				"	2. to delete an element from the end of the list.\n"
				"	3. to delete an element from any position of the list.\n"
				"	4. to delete the entire list.\n"
			      );
			printf("::? ");
			read_int(&ch);
			
			switch (ch) {
			case 1:
				del_first();
				break;
			case 2:
				del_last();
				break;
			case 3:
				del_pos();
				break;
			case 4:
				del_list();	
				break;
			default:
				break;
			}
			break;
		case 3:
			update();
			break;
		case 4:
			search();
			break;
		case 5:
			reverse();
			break;
		case 6:
			display();
			break;
		case 7:
			flags = true;
			break;
		case 8:
			menu();
			break;
		default:
			(void)fprintf(stdout, "Invalid Input...!\n");
			break;
		}
	} while (!flags);
	exit(EXIT_SUCCESS);
}


static void
menu(void)
{
	(void)fprintf(stdout,
		"	1. to add an en element to the list.\n"
		"	2. to delete an element from the list.\n"
		"	3. to update an element.\n"
		"	4. to search for an element in the list.\n"
		"	5. to reverse list.\n"
		"	6. to display list.\n"
		"	7. to exit.\n"
	      );
	return;
}
