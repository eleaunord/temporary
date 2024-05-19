
#include "../includes/tokens.h"

// void str_before_separator(char *token, t_position_tracker *p, t_command **command)
// {
// 	char *new_token;
	
// 	(void)command;
// 	new_token = create_token(token, p->start, p->i - 1);
// 	// if (new_token[0])
// 	// 	ft_lstadd_back_commands(command, token);
// 	free(new_token);
// }

// void update_separator(char *token, int *index, t_command **cmd, int *start)
// {
// 	char *new_token;

// 	new_token = NULL;
// 	(void)start;
// 	(void)cmd;
// 	if (token[*index] == '|')
// 	{
// 		new_token = create_token(token, *index, *index);
// 		// ft_lstadd_back_commands(cmd, new_token);
// 	}
// 	free(new_token);
// }
// char *trim_separators(char *token, t_command **command)
// {
// 	char *new_token;
// 	t_position_tracker *p;

// 	p = malloc(sizeof(t_position_tracker));
// 	p->i = 0;
// 	p->start = 0;
// 	while ((token[p->i]) == SPACE_ || (token[p->i] >= 9 && token[p->i] <= 13))
// 	{
// 		p->i++;
// 		p->start++;
// 	}
// 	while (token[p->i])
// 	{
// 		if (token[p->i] == '<' || token[p->i] == '>' || token[p->i] == '|')
// 		{
// 			//non emty substring before the delimiter
// 			if (p->i > p->start)
// 				str_before_separator(token, p, command);
// 			update_separator(token, &p->i, command, &p->start);
// 		}
// 		else
// 			p->i++;
// 	}
// 	if (p->i > p->start)
// 		return(create_token(token, p->start, p->i));
// 	else
// 		return(ft_strdup(""));
// 	free(p);
// 	free(token);
// 	return (new_token);
// }