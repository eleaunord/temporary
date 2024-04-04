/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:27:07 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/04 14:59:20 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	*trim(char const *s1, char const *set)
{
	char	*new;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	new = ft_substr(s1, start, (end - start) + 1);
	if (!new)
		return (NULL);
	return (new);
}

int	get_num_lines(char *path, t_game *game)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Map cannot be opened.", game);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		lines++;
		free(tmp);
	}
	close(fd);
	return (lines);
}

t_map	*map_new(int cols, int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->body = ft_calloc(rows + 1, sizeof(char *));
	if (!map->body)
	{
		// free(map->body);
		return (NULL);
	}
	map->cols = cols;
	map->rows = rows;
	return (map);
}

void	read_map(char *path, t_game *game)
{
	int				fd;
	char			*tmp;
	int	i;

	i = 0;
	game->map = map_new(0, get_num_lines(path, game));
	if (!game->map)
		exit_error("Allocation error on map. ", game);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Map cannot be opened.", game);
	while (i < game->map->rows)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			exit_error("Allocation failed on map lines. ", game);
		game->map->body[i] = trim(tmp, "\n");
		if (!game->map->body[i])
			exit_error("Allocation failed on map lines 2.", game);
        i++;
		free(tmp);
	}
	close(fd);
    check_map(game);
}