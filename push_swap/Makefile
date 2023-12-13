NAME = push_swap.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c \
push.c \
reverse.c \
rotate.c \
swap.c \
lib.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus