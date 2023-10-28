CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu99

OBJ = rocket.o utils.o reader.o
TOBJ = test_utils.o

test: CFLAGS += -fsanitize=address -g
test: LDLIBS += -lcriterion -fsanitize=address
test: $(OBJ) $(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)
	./test

clean:
	$(RM) $(OBJ) $(TOBJ) test

.PHONY: clean test
