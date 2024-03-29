/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:27:07 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/29 18:21:02 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// static void	get_cols(t_map *map, int fd)
// {
// 	int		count;
// 	char	*temp;

// 	count = 0;
// 	temp = get_next_line(fd);
// 	while (temp)
// 	{
// 		count++;
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
//     free(temp);
// 	if (count == 0)
// 		exit_error("Empty map.");
// 	map->cols = count;
// 	close(fd);
// }


// static void get_rows(t_map *map, int fd)
// {
//     char *line = get_next_line(fd); // Read the first line

//     if (line == NULL)
//         exit_error("Empty map.");

//     int rows = ft_strlen(line); // Get the rows of the first line
//     free(line); // Free the memory allocated for the line

//     map->rows = rows; // Set the rows of the map
//     close(fd);
// }

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

// static void fill_map_body(char *path, t_map *map)
// {
//     int fd;
//     int i;

//     fd = open(path, O_RDONLY);
//     if (fd < 0)
//         exit_error("Map cannot be opened.");
//     i = 0;
//     while (i < (map->rows - 1))
//         map->body[i++] = get_next_line(fd);
//     map->body[i] = NULL;
//     close(fd);
//     // trim?
//     i = 0;
// 	while (i < (map->rows - 1))
// 	{
// 		map->body[i] = ft_trim(map->body[i], "\n");
// 		if (!map->body[i])
// 			exit_error("Malloc error. ");
// 		i++;
// 	}
// }

int	get_num_lines(char *path)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Map cannot be opened.");
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
		free(map);
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
	game->map = map_new(0, get_num_lines(path));
	if (!game->map)
		exit_error("Allocation error on map. ");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Map cannot be opened.");
	while (i < game->map->rows)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			exit_error("Allocation failed on map lines. ");
		game->map->body[i] = trim(tmp, "\n");
		if (!game->map->body[i])
			exit_error("Allocation failed on map lines 2." );
        i++;
		free(tmp);
	}
	close(fd);
    check_map(game);
}

// void    read_map(char *path, t_map *map)
// {
//     int i;
//     int     fd;
//     int count;
//     // t_map   *map;

//     fd = open(path, O_RDONLY);
//     if (fd < 0)
//         exit_error("Map cannot be opened.");
//     // HEIGHT
//     get_cols(map, fd);
//     // initializing the body of the map
//     map->body = (char **) malloc (sizeof(char *) * (map->cols + 1));
//     if (map->body == NULL)
// 	{
// 		 exit_error("Memory Error.");
// 	}
// 	// i = 0;
// 	// while (i < map->cols)
// 	// 	map->body[i] = NULL;
// 	//LENGTH
// 	char *line;
// 	count = 0;
//     while (1) // Infinite loop to read all lines
// 	{
//         count++;
// 		line = get_next_line(fd);
// 		if (!line) // If line is NULL, indicating end of file or error
// 		{
// 			break; // Exit the loop
// 		}
// 		printf("%s", line);
// 		free(line); // Free the line after using it
// 	}
// 	// line = get_next_line(fd); // Read the first line
//     // if (!line)
//     //     exit_error("Empty map.");
    
//     // while (line)
//     // {
//     //     count++;
//     //     line = get_next_line(fd);
//     //     printf("%s", line);
//     //     free(line);
        
//     // }
//     if (count == 0)
//         exit_error("Empty map.");
//     map->rows = count; // Set the rows of the map
//     close(fd);

//     // fill up map body
//     fill_map_body(path, map);
        
//     //checking if the map is correctly structured
// 	i = 0;
//     // if (check_map(map) == false)
//     // {
//     //     while (i < map->cols)
//     //         free(map->body[i++]);
//     //     exit_error("Problem with map structure. ");
//     // }
// }

// #include <stdio.h>
// #include <fcntl.h>

// int	main(int argc, char *argv[])
// {
// 	char	*line;
// 	int		fd;

// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		while (1) // Infinite loop to read all lines
// 		{
// 			line = get_next_line(fd);
// 			if (!line) // If line is NULL, indicating end of file or error
// 			{
// 				break; // Exit the loop
// 			}
// 			printf("%s", line);
// 			free(line); // Free the line after using it
// 		}
// 		close(fd);
// 	}

// 	return (0);
// }