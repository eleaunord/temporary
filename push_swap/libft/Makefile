NAME = libft
CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_printf.c \
print_char.c \
print_dec.c \
print_hexa_low.c \
print_hexa_up.c \
print_str.c \
print_un.c \
print_void.c \

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
	
.c.o:
	@printf "\r\033[K[libft] \033[0;32mCompilation : $<\033[0m"
	@$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	@printf "\r\033[K[libft] \033[0;32mLinking...\033[0m"
	@ar rc $(NAME) $(OBJS)
	@printf "\r\033[K[libft] \033[0;32mDone!\033[0m\n"

clean:
	@rm -f $(OBJS)
	@printf "[libft] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[libft] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re

# BONUS_OBJS = $(BONUS:.c=.o)

# all : $(NAME)

# $(NAME) : $(OBJS)
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)

# a.out : $(BONUS_OBJS)
# 	$(CC) $(FLAGS) -o $@ -c $^

# %.o : %.c
# 	$(CC) $(FLAGS) -o $@ -c $<


# clean :
# 	rm -f $(OBJS) $(BONUS_OBJS)

# fclean : clean
# 	rm -f $(NAME)

# re : fclean all

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# .PHONY: all clean fclean re bonus


# OBJS = $(FILES:.c=.o)
	
# .c.o:
# 	@printf "\r\033[K[libft] \033[0;32mCompilation : $<\033[0m"
# 	@$(CC) $(FLAGS) -c $< -o $@

# all:	$(NAME_LIBFT)

# $(NAME_LIBFT): $(OBJS)
# 	@printf "\r\033[K[libft] \033[0;32mLinking...\033[0m"
# 	@ar rc $(NAME_LIBFT) $(OBJS)
# 	@printf "\r\033[K[libft] \033[0;32mDone!\033[0m\n"

# clean:
# 	@rm -f $(OBJS)
# 	@printf "[libft] \033[1;31mCleaned .o!\033[0m\n"

# fclean: clean
# 	@rm -f $(NAME_LIBFT)
# 	@printf "[libft] \033[1;31mCleaned all!\033[0m\n"

# re: fclean all

# .PHONY: all clean fclean re