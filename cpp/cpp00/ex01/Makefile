NAME		=	phonebook
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -g3 -std=c++98
SRC			=	main.cpp Contact.cpp PhoneBook.cpp 
OBJ			=	$(SRC:.cpp=.o)
RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)