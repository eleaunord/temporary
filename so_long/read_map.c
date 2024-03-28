/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:27:07 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/28 15:43:08 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	get_height(t_map *map, int fd)
{
	int		count;
	char	*temp;

	count = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		count++;
		free(temp);
		temp = get_next_line(fd);
	}
    free(temp);
	if (count == 0)
		exit_error("Empty map.");
	map->height = count;
	close(fd);
}


// static void get_length(t_map *map, int fd)
// {
//     char *line = get_next_line(fd); // Read the first line

//     if (line == NULL)
//         exit_error("Empty map.");

//     int length = ft_strlen(line); // Get the length of the first line
//     free(line); // Free the memory allocated for the line

//     map->length = length; // Set the length of the map
//     close(fd);
// }



void    read_map(char *path, t_map *map)
{
    int i;
    int     fd;
    // t_map   *map;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        exit_error("Map cannot be opened.");
    // HEIGHT
    get_height(map, fd);
    // initializing the body of the map
    map->body = (char **) malloc (sizeof(char *) * (map->height + 1));
    if (map->body == NULL)
	{
		 exit_error("Memory Error.");
	}
	// i = 0;
	// while (i < map->height)
	// 	map->body[i] = NULL;
	//LENGTH
	char *line;
	char *map;
	
	line = get_next_line(fd); // Read the first line

    if (line == NULL)
        exit_error("Empty map.");

	
    int length = ft_strlen(line); // Get the length of the first line
    free(line); // Free the memory allocated for the line

    map->length = length; // Set the length of the map
    close(fd);
    //checking if the map is correctly structured
	i = 0;
    if (check_map(map) == false)
    {
        while (i < map->height)
            free(map->body[i++]);
        exit_error("Problem with map structure. ");
    }
}