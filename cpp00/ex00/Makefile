SRC		=	megaphone.cpp
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	megaphone

$(NAME):
			$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
