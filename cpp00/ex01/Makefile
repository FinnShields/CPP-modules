SRC		=	main.cpp Contact.cpp PhoneBook.cpp
INC		=	Contact.hpp PhoneBook.hpp
NAME	=	phonebook
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(SRC) $(INC)
				$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re