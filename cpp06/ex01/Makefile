NAME	=	serializer
CC		=	c++
FLAGS	=	-Wall -Werror -Wextra -std=c++17
SRC		=	main.cpp Serializer.cpp
OBJ		=	$(SRC:.cpp=.o)
INCLUDE	=	Serializer.hpp

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
				$(CC) $(FLAG) $(OBJ) -o $(NAME)
				@echo "*** Compiled the serializer, run with ./serializer ***"

%.o:		%.cpp
				$(CC) $(FLAGS) -c $< -o $@

clean:
				rm -f $(OBJ)
				@echo "cleaned"

fclean:		clean
				rm -f $(NAME)
				@echo "fcleaned"

re:			fclean all

.PHONY:		all clean fclean re