CC	=	gcc
NAME	=	server
NAME_2	=	client

SRC	=	server.c

SRC_2	=	client.c

OBJ	=	$(SRC:.c=.o)
OBJ_2	=	$(SRC_2:.c=.o)
	
CFLAGS	+=	-Wall -Wundef -Wextra -Wpedantic

all:	$(NAME) $(NAME_2)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAME_2): $(OBJ_2)
	$(CC) -o $(NAME_2) $(OBJ_2) $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(OBJ_2)

fclean: clean
	rm -rf $(NAME_2) $(NAME)

re: fclean all
