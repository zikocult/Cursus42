SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o
	$(CC) -o $@ $< 

client: client.o
	$(CC) -o $@ $< 

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
