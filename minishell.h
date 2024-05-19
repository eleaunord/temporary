#ifndef TOKENS_H
# define TOKENS_H

// HEADERS
# include "../libft/libft.h"

// Librairies
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>


// TOKEN LIST

/*

Règles de Tokenisation :

	Redirections :
		< devient le token INPUT (1).
		> devient le token TRUNC (3).
		<< devient le token HEREDOC (2).
		>> devient le token APPEND (4).

	Premier Token :
		Le premier token d'une ligne de commande est CMD (6),
			sauf s'il s'agit d'une redirection.

	Arguments :
		Tous les tokens suivants un CMD ou une redirection (INPUT, TRUNC,
			HEREDOC, APPEND) sont des ARG (7).

	Pipes :
		| devient le token PIPE (5).
		Après un PIPE, le prochain token est soit une redirection, soit un CMD.

*/

# define INPUT 1
# define HEREDOC 2
# define TRUNC 3
# define APPEND 4
# define PIPE 5
# define CMD 6
# define ARG 7
# define IDENTIFIER 8
# define SEPARATOR 9
# define L_PARENT 10
# define R_PARENT 10
// Define for a clearer code (ASCII)
# define SPACE_ 32
# define DOUBLE_QUOTE 34
# define SINGLE_QUOTE 39

// TOKEN LINKED LIST

/*

liste chainee de token pour chaque elements de la ligne de commande
-> str et int pour chaque maillon
-> str = WORD aka ce qui est visuel (cat,
		| ) ; int = token aka type de token (CMD, PIPE)

*/

// MINISHELL STRUCT
typedef struct s_list
{
	void			*content;
	int				type;
	struct s_list	*next;
	int				loop;
}					t_list;

typedef struct s_command
{
	char				*token;
	int					length;
	int					type;
	struct s_command	*next;
}						t_command;

typedef struct s_position_tracker
{
	int					start;
	int					i;
}						t_position_tracker;

int						is_space(const char num);
int						is_separator(char *c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					process_in_quotes(char *line, t_position_tracker *p,
							t_command **cmd, t_list *mini);
char					*create_token(char *str, int start, int end);
char					*ft_strjoin(char const *s1, char const *s2);

void	ft_putendl_fd(char const *s, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content, int type);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t bytes);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_bzero(void *s, size_t bytes);
char	*ft_strdup(const char *s);

#endif