SERVER	= server.c server_helper.c

CLIENT	= client.c client_helper.c

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g

PRINTF	= libftprintf.a

all: server client

server:
	$(CC) $(SERVER) $(PRINTF) -o server

client:
	$(CC) $(CLIENT) $(PRINTF) -o client

clean:
	rm -f server
	rm -f client

re: clean all