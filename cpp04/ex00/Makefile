NAME	=	animal
SRC		=	main.cpp Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp
I		=	Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
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