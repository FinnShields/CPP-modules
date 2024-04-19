NAME	=	materia
C		=	c++
FLAGS	=	-Wall -Werror -Wextra
SRC		=	AMateria.cpp Character.cpp Cure.cpp Ice.cpp \
			main.cpp MateriaSource.cpp
I		=	AMateria.hpp Character.hpp Cure.hpp Ice.hpp\
			ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

all:		$(NAME)

$(NAME):	$(SRC) $(I)
				$(C) $(FLAGS) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re