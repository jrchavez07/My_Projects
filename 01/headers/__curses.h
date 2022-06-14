#ifndef __CURSES_H_INCLUDED
#define __CURSES_H_INCLUDED

#include <stdio.h>
#include <sys/cdefs.h>

extern char buf[BUFSIZ];
extern int  bufp;

__BEGIN_DECLS

extern int getch();
extern void ungetch(int);

__END_DECLS
#endif	/* __CURSES_H_INCLUDED */
