NAME	=	zombie
C		=	c++
FLAGS	=	-Wall -Werror -Wextra
SRC		=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
INC		=	Zombie.hpp

all:		$(NAME)

$(NAME):	$(SRC) $(INC)
				$(C) $(FLAGS) $(SRC) -o $(NAME)

clean:
			rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re