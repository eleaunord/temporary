// readline => Reads a line from the standard input and returns it.
// rl_clear_history =>	Clears the readline history list.
// rl_on_new_line =>	Prepares readline for reading input on a new line.
// rl_replace_line 	=> Replaces the content of the readline current line buffer.
// rl_redisplay =>	Updates the display to reflect changes to the input line.
// add_history =>	Adds the most recent input to the readline history list.

#include "../../includes/minishell.h"

/*

	1. Getting the string with READLINE
		- eg : "cat -e|grep>file.txt ' aliens';"

	2. Splitting input string into a linked list of tokens with ft_split_tokens
		- eg : {"cat"} -> {"-e|grep>file.txt"} -> {"' aliens';"} -> NULL

	3. Re-cutting according to the operators (symbols: >>, >, <, |,
		;) with trim_operators
		- eg : {"cat"} -> {"-e"} -> {"|"} -> {"grep"} -> {">"} -> {"file.txt"}
			-> {"' aliens'"} -> {";"} -> NULL

*/


char *create_token(char *str, int start, int end)
{
	char *substring;
	int i;
	int j;

	if (start > end)
		return(ft_strdup(""));
	substring = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (substring == NULL)
		exit(1);
	i = 0;
	j = start;
	while (j <= end)
	{
		if (str[j] == '\0')
			break ;
		if (is_space(str[j]))
			substring[i++] = str[j];
		j++;
	}
	substring[i] = '\0';
	
	return (substring);
}

void process_token(char *line, t_command **command, t_position_tracker *pos, t_list *minishell)
{
	char *copy;

	(void)command;
	(void)minishell;
	// copy = trim_separators(create_token(line, pos->start, pos->i), command);
	copy = create_token(line, pos->start, pos->i);
	// ft_lstadd_back_commands(command, line);
	printf("Token: %s\n", (char *)copy);
	free(copy);
}
/*

ft_split_tokens : splitting the input on the command line into tokens

	INIT VARS
	1. allocate memory for a t_position_tracker structure
	2. pos->i is the index of the current line

	WHILE LOOP
	1. if the next char is the end of the line or current char is a space then it's the end of a token
	2. create_token to handle token creation
	3. update pos->start to the next char (after the current one)

*/

void	ft_split_tokens(char *line, t_list *minishell, t_command **command)
{
	t_position_tracker	*pos;

	pos = (t_position_tracker *)malloc(sizeof(t_position_tracker));
	pos->i = 0;
	pos->start = 0;
	while (line[pos->i])
	{
		if (line[pos->i + 1] == '\0' || (!is_space(line[pos->i])))
		{
			process_token(line, command, pos, minishell);
			pos->start = pos->i + 1;
		}
		else if (line[pos->i] == '\'' || line[pos->i] == '"')
			process_in_quotes(line, pos, command, minishell);
		// #

		pos->i++;
	}
	free(pos);
}
// buffer : where the categorized characters will be sotred

int	tokenizer(char *input, t_list *minishell, t_command **command)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * ft_strlen(input) + 1);
	ft_bzero(buffer, ft_strlen(input) + 1);
	// if (!check_syntax(buffer, minishell))
	// {
	// 	free(buffer);
	// 	return (0);
	// }
	free(buffer);
	ft_split_tokens(input, minishell, command);
	return (1);
}

// static void	set_input(t_list *minishell)
// {
// 	// minishell->inf.file = 0;
// 	// minishell->inf.eof = 0;
// 	// minishell->ouf.file = 0;
// 	// minishell->inf.flag = 0;
// 	// minishell->ouf.flag = 0;
// 	// minishell->cmds = 0;
// 	minishell->loop = 1;
// }

int	main(int argc, char *argv[])
{
	char	*input_line = NULL;
	t_list	*minishell = NULL;
	t_command *command;

	int flag = 1;

	(void)argc;
	(void)argv;
	// set_input(&minishell);
	while (flag == 1)
	{
		input_line = readline("prompt> ");
		if (input_line == NULL)
		{
			rl_clear_history();
			// printf("exit\n");
			flag = 0;
			// handler_sigint(SIGTERM);
		}
		if (!tokenizer(input_line, minishell, &command))
		{
			add_history(input_line);
			free(input_line);
			return (0);
		}
		
		add_history(input_line);
		free(input_line);
		return (1);
		// exec command
		// free_input(&minishell);
	}

	ft_lstclear(&minishell, free);
	free(input_line);
	return (0);
}
