

#include "../../includes/minishell.h"

int	is_space(const char num)
{
	if (num == 32 || (num >= 9 && num <= 13))
		return (0);
	else
		return (1);
}

int	is_separator(char *c)
{
	if (!ft_strncmp(c, "<", 1) || !ft_strncmp(c, ">", 1) || !ft_strncmp(c, "|",
			1) || !ft_strncmp(c, "(", 1) || !ft_strncmp(c, ")", 1))
		return (0);
	return (1);
}