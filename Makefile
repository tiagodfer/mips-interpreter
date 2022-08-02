CC=gcc
CFLAGS=-g0 -Wall -pedantic -O3 -lncurses -ltinfo
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BIN=bin
NAME=interpreter
SUBMITNAME=tiagodiasferreira.zip

all: $(BIN)/$(NAME)

debug: CFLAGS=-g3 -Wall
debug: $(BIN)/$(NAME)

$(BIN)/$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)/$(NAME)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r main $(BIN)/* $(OBJ)/* $(SUBMITNAME)

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(SRC)/* $(BIN)/$(NAME) $(OBJ)/* Makefile
