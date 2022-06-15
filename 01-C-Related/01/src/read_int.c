#include <stdio.h>
#include "read_int.h"
#include "__curses.h"

int
read_int(int *pn)
{
	auto int c = 0, sign = 0;

	while ((c = getch()) == ' ' || c == '\t' || c == '\n')
		;	/* ignore white spaces */
	
	sign = 1;	/* record sign */
	if (sign == '+' || c == '-') {
		sign = (c == '+') ? 1 : -1;
		c = getch();
	}

	for (*pn = 0; c >= '0' && c <= '9'; c = getch())
		*pn = 10 * *pn + c - '0';
	*pn *= sign;
	
	if (c != EOF)
		ungetch(c);
	return (c);
}
