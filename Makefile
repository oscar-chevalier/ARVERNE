CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu99

OBJ = main.o

test:
    CFLAGS += -fsanitize=address

clean:
	$(RM) $(OBJ)

.PHONY: clean
