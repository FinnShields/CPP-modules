NAME	=	sed
C		=	c++
FLAGS	=	-Wall -Werror -Wextra
SRC		=	main.cpp utils.cpp
INC		=	sed.hpp

all:		$(NAME)

$(NAME):	$(SRC) $(INC)
				$(C) $(FLAGS) $(SRC) -o $(NAME)

clean:
			rm -f $(NAME)
			rm *.txt *.replace

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re