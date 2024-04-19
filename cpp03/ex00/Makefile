NAME	=	clap_trap
SRC		=	main.cpp ClapTrap.cpp
INC		=	ClapTrap.hpp
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