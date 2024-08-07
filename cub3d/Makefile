# VARIABLES
## binary
NAME = cub3D

## compilation
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))

## bash commands
RM = rm -f

## valgrind
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

## directories
INCLUDES_DIR = ./includes ./mlx
OBJ_DIR = ./obj

## libs
MLIBX_PATH = ./mlx
MLIBX = $(MLIBX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLIBX_PATH) -lmlx -lXext -lX11

LIBMATH_FLAGS = -lm

## source files
SRCS = main.c

## object files
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(MLIBX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX_FLAGS) $(LIBMATH_FLAGS)

$(MLIBX):
	make -C $(MLIBX_PATH)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(MLIBX_PATH)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	clear
	./$(NAME) $$MAP

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $$MAP

.PHONY: all clean fclean re run valgrind
