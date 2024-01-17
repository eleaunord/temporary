NAME = push_swap
CC = cc
RM	=	rm -f
FLAGS = -Wall -Werror -Wextra -I.
SRCS = push_swap.c \
push.c \
reverse.c \
rotate.c \
swap.c \
errors.c \
sort.c \
utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L./libft

clean:
	${MAKE} clean -C ./libft
	$(RM) $(OBJS) 

fclean:		clean
	${MAKE} fclean -C ./libft
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re


# MINE
# $(NAME) : $(OBJS)
# 	ar rc $(NAME) $(OBJS)

# %.o : %.c
# 	$(CC) $(FLAGS) -o $@ -c $<

# clean :
# 	rm -f $(OBJS)

# fclean : clean
# 	rm -f $(NAME)

# re : fclean all

# .PHONY: all clean fclean re bonus

# SASHA
# SRCS	=	srcs/main.c \
# 			srcs/check_arg.c

# FILES_BONUS = \

# OBJS	=	$(SRCS:.c=.o)

# CC	=	cc

# RM	=	rm -f

# CFLAGS	=	-Wall -Wextra -Werror -I.

# NAME	=	push_swap

# all:		$(NAME)

# $(NAME): $(OBJS)
# 	${MAKE} -C ./libft
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

# clean:
# 	${MAKE} clean -C ./libft
# 	$(RM) $(OBJS) 

# fclean:		clean
# 	${MAKE} fclean -C ./libft
# 	$(RM) $(NAME)

# re:		fclean all

# .PHONY:		all clean fclean re