NAME	=	frag_trap
SRC		=	main.cpp ClapTrap.cpp FragTrap.cpp
INC		=	ClapTrap.hpp FragTrap.hpp
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