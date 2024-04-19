NAME	=	weapon
C		=	c++
FLAGS	=	-Wall -Werror -Wextra
SRC		=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
INC		=	HumanA.hpp HumanB.hpp Weapon.hpp

all:		$(NAME)

$(NAME):	$(SRC) $(INC)
				$(C) $(FLAGS) $(SRC) -o $(NAME)

clean:
			rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re