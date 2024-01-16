#include "push_swap.h"

//dans la libft
int ft_lstsize(t_node *lst) 
{
    int size;

    size = 0;
    while (lst->next != NULL)
    {
        ++size;
        lst = lst->next;
    }
    return (size);
}

void    ft_lstadd_front(t_node **lst, t_node *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}

t_node    *ft_lstlast(t_node *lst)
{

    if (!lst)
        return (NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return ((t_node *)lst);
}

void    ft_lstadd_back(t_node **lst, t_node *new)
{
    t_node  *last;

    if (lst == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}


static	int	wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static	char	*wordcopy(char *s, char c, int i)
{
	int		index;
	char	*word;

	index = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] != c))
	{
		index++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * index + 1);
	if (!word)
		return (NULL);
	i = i - index;
	index = 0;
	while (s[i] && (s[i] != c))
	{
		word[index] = s[i];
		i++;
		index++;
	}
	word[index] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (wordcount((char *)s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && (s[i] != c))
		{
			tab[j] = wordcopy((char *)s, c, i);
			j++;
		}
		while (s[i] && (s[i] != c))
			i++;
	}
	tab[j] = 0;
	return (tab);
}