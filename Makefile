CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu99

OBJ = rocket.o utils.o reader.o
TOBJ = test_utils.o

test: CFLAGS += -fsanitize=address -g
test: LDLIBS += -lcriterion -fsanitize=address
test: $(OBJ) $(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)
	./test

debug: CFLAGS += -g
debug: $(OBJ) debug.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ) $(TOBJ) test debug debug.o

.PHONY: clean test
