NAME	=	animal
SRC		=	main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
I		=	Animal.hpp Dog.hpp Cat.hpp Brain.hpp
C		=	c++
FLAG	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRC) $(I)
				$(C) $(FLAG) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re