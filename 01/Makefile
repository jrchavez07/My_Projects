CC= gcc
CFLAGS= -Wall -Wextra -Wpedantic -Werror -O3 -pg --save-temps -fPIC
CFILES = *.c
OBJ= *.o
TARGET= main 

all:	exec
 	# gprof ./main gmon.out > analysis.txt
 	# valgrind -s --leak-check=yes ./${TARGET}

exec:	${TARGET}
	./${TARGET}

${TARGET}:	${OBJ}
	# ${CC} ${CFLAGS} ${OBJ} -o $@ -lcurses -ltinfo
	${CC} ${CFLAGS} ${OBJ} -o $@	

${OBJ}:	${CFILES}
	${CC} ${CFLAGS} -c ${CFILES}

clean:
	rm -rfv ${TARGET} ${OBJ} *.i *.s *.txt *.out
