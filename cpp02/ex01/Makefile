NAME	=	fixed
SRC		=	main.cpp Fixed.cpp
INC		=	Fixed.hpp
C		=	c++
FLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRC) $(INC)
				$(C) $(FLAGS) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHOMY:		all clean fclean re