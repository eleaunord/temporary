/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:56:48 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/28 13:43:03 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool    check_characters(t_map *map)
{
    int x;
    int y;
    
    map->collectibles = 0;
    map->exit = 0;
    map->player_pos = 0;
    x = 0;
    while(x < map->length)
    {
        y = 0;
        while(y < map->height)
        {
            if (map->body[x][y] == 'C')
                map->collectibles++;
            else if (map->body[x][y] == 'E')
                map->exit++;
            else if (map->body[x][y] == 'P')
                map->player_pos++;
            y++;
        }
        x++;
    }
    if (map->exit == 0 || map->exit > 1 || map->player_pos == 0 || map->player_pos > 1 || map->collectibles == 0)
        return (false);
    return (true);
}

static bool	check_walls(t_map *map)
{
    int     i;
    
    i = 0;
    //vertical walls
    while (i < map->length)
    {
        //top and bottom characters
        if (map->body[i][0] != '1' || map->body[i][map->height - 1] != '1')
            return (false);
        i++;
    }
    i = 0;
    //horizontal walls
    while (i < map->height)
    {
        //left and right characters
        if (map->body[0][i] != '1' || map->body[map->length - 1][i] != '1')
            return (false);
        i++;
    }
    return (true);
}

static bool	check_rectangle(t_map *map)
{
    size_t i;
    size_t len;

    len = map->length;
    i = 0;
    while (map->body[i] != NULL)
    {
        //if the length of the line is not the same as the length of the rectangle
        if (len != ft_strlen(map->body[i]))
            return (false);
        i++;
    }
    return (true);
}

bool   check_map(t_map *map)
{
    if (check_rectangle(map) == true && check_walls(map) == true && check_characters(map) == true)
        return (true);
    else
        return (false);
}
