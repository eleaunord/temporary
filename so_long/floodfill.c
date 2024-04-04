/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:03:23 by nnuno-ca          #+#    #+#             */
/*   Updated: 2024/04/03 16:30:11 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			return (1);
		if (str[i] == 'P')
			return (2);
		i++;
	}
	return (0);
}

void	checkflood(char **copymap, t_game *game)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (copymap[i])
	{
		ret += checkstr(copymap[i]);
		free(copymap[i]);
		i++;
	}
	free (copymap);
	if (ret == 1)
		exit_error("Collectible error : no possible path. ", game);
	else if (ret == 2)
		exit_error("Player error :No possible path. ", game);
}

int	fill(char **copy, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map->cols
		|| y >= game->map->rows || copy[y][x] == '1' || copy[y][x] == 'F')
		return (1);
	if (copy[y][x] == 'E')
	{
		game->flag = 1;
		return (1);
	}
	copy[y][x] = 'F';
	fill(copy, x + 1, y, game);
	fill(copy, x - 1, y, game);
	fill(copy, x, y + 1, game);
	fill(copy, x, y - 1, game);
	return (game->flag);
}

void	find_perso(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->body[i])
	{
		j = 0;
		while (game->map->body[i][j])
		{
			if (game->map->body[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}

char	*ft_stdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**mapcopy(t_game *game)
{
	int		i;
	char	**new;

	i = 0;
	while (game->map->body[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
		exit_error("Error with the map copy.", game);
	i = 0;
	while (game->map->body[i])
	{
		new[i] = ft_stdup(game->map->body[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}

void	floodfill(t_game *game)
{
	char	**copymap;
	int		x;
	int		y;

	game->flag = 0;
	copymap = mapcopy(game);
	find_perso(game, &x, &y);
	if (!fill(copymap, x, y, game))
		exit_error("Error with the exit.", game);
	checkflood(copymap, game);
}
