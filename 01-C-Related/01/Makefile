CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Werror -O2 -pg --save-temps -fPIC
LDFLAGS=

SRC=src
OBJ=obj
HDR=headers
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.h)
BIN=main

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJS)	-o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(BIN)
	$(RM) *.i
	$(RM) *.s
	$(RM) *.s
	$(RM) *.txt
	$(RM) *.out

