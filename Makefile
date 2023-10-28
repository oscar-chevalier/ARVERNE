CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu99

OBJ = rocket.o utils.o reader.o
TOBJ = test_utils.o

test: CFLAGS += -fsanitize=address
test: LDLIBS += -lcriterion -fsanitize=address
test: $(OBJ) $(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)
	./test

clean:
	$(RM) $(OBJ)

.PHONY: clean
