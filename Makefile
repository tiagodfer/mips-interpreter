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

debug: CFLAGS=-g3 -Wall -pedantic -lncurses -ltinfo
debug: $(BIN)/$(NAME)

$(BIN)/$(NAME): $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)/$(NAME)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

clean:
	$(RM) -r main $(BIN)/* $(OBJ)/* $(SUBMITNAME)

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(SRC)/* $(BIN)/$(NAME) $(OBJ)/* Makefile
