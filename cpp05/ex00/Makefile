NAME	=	bureaucrat
SRC		=	main.cpp Bureaucrat.cpp
INCLUDE	=	Bureaucrat.hpp
CC		=	c++
FLAG	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(SRC) $(INCLUDE)
				$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re