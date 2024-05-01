
NAME = philo

SRC = main.c utils.c init.c routine.c waiter.c end.c

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

