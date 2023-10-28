CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu99

OBJ = main.o rocket.o

test: $(OBJ)
	CFLAGS += -fsanitize=address

clean:
	$(RM) $(OBJ)

.PHONY: clean