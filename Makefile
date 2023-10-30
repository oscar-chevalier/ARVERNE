CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu99

SRCS=$(wildcard *.c) $(wildcard structures/*.c)
OBJ=$(SRCS:.c=.o)
TOBJ = test_utils.o

all: test

test: CFLAGS += -fsanitize=address -g
test: LDLIBS += -lcriterion -fsanitize=address
test: $(OBJ) $(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)
	./test
debug: CFLAGS = -Wall -Wextra -std=gnu99
debug: CFLAGS += -g
debug: $(OBJ) debug.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

debugs: CFLAGS += -g -fsanitize=address
debugs: LDLIBS += -fsanitize=address
debugs: $(OBJ) debug.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ) $(TOBJ) test debug debug.o

.PHONY: clean test
