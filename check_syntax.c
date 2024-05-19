#include "../includes/tokens.h"

/*
Syntax errors to check
	1. if there is a pipe at the end of the buffer
	2. if there is a redirection symbol ('<' or '>') at the end of the buffer
	3. for continuous pipes ('||') in the buffer
	4. unmatched quotes
	5. misplaced redirection
	4. ...
*/

// void	categorize(char *str, char *buf)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i]) == SPACE_ || (str[i] >= 9 && str[i] <= 13))
// 			buf[i] = 's';
// 		else if (str[i] == SINGLE_QUOTE)
// 			buf[i] = 'q';
// 		else if (str[i] == DOUBLE_QUOTE)
// 			buf[i] = 'Q';
// 		else if (str[i] == '|')
// 			buf[i] = 'p';
// 		else if (str[i] == '<' || str[i] == '>')
// 			buf[i] = 'r';
// 		else if (str[i] == '$')
// 			buf[i] = 'V';
// 		else
// 			buf[i] = 'd';
// 		i++;
// 	}
// }

// int check_syntax(char *buf, t_list *minishell)
// {
	// categorize(input, buffer);
// 	return (0);
// }

