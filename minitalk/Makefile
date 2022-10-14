CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_SERVER = server.c utils.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
SRC_CLIENT = client.c utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SERVER = server
CLIENT = client

NAME = minitalk

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_SRV_BONUS)
	rm -f $(OBJ_CLIENT) $(OBJ_CLT_BONUS)

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
