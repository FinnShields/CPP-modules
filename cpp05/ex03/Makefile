NAME	=	bureaucrat
SRC		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
INCLUDE	=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp Intern.hpp
CC		=	c++
FLAG	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(SRC) $(INCLUDE)
				$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
				rm -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re