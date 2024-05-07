
NAME = philo

SRC = main.c init.c routine.c death.c time.c utils.c check_input.c 

MANPATH = $(SRC)

FLAGS = -Wall -Wextra -Werror -g3 -O3 -pthread

HEADER = philo.h

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH) $(SANITIZER)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all
