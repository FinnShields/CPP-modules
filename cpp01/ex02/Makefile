NAME	=	brain
C		=	c++
FLAGS	=	-Wall -Werror -Wextra
SRC		=	main.cpp

all:		$(NAME)

$(NAME):	$(SRC)
				$(C) $(FLAGS) $(SRC) -o $(NAME)

clean:
			rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re