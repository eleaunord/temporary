# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 15:01:55 by eleroty           #+#    #+#              #
#    Updated: 2024/03/25 16:14:38 by eleroty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = init.c

RM = rm -f
#miblx compilation
MLX	= -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus