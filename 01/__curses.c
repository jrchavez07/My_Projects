#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#include "headers/__curses.h"

char buf[BUFSIZ];
int bufp = 0;

int
getch(void)
{
	return ((bufp > 0) ? buf[--bufp] : getchar());
}


void
ungetch(int c)
{
	if (bufp > BUFSIZ)
		errx(EXIT_FAILURE, "ungetch: too many characters.\n");
	else
		buf[bufp++] = c;
	return;
}
