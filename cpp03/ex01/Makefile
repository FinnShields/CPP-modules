NAME	=	scav_trap
SRC		=	main.cpp ClapTrap.cpp ScavTrap.cpp
INC		=	ClapTrap.hpp ScavTrap.hpp
C		=	c++
FLAG	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(SRC) $(INC)
				$(C) $(FLAG) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re