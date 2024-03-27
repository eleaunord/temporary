/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:42 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/27 17:46:57 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// create 2 or more images to hold frames + one tmp

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	close_window(t_game *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int press_keys(int keycode, void *vars)
{
    if (keycode == ESC)
        close_window(vars);
    return (0);
}

// char	**load_map(t_stc *stc, char *path)
// {
// 	int		map_fd;
// 	char	**map;
// 	char	*map_line_buff;
// 	char	*map_gnl_buff;
// 	char	*map_line;

// 	map_fd = open(path, O_RDONLY);
// 	if (map_fd < 0)
// 		exit_error(stc, "Unable to open the map");
// 	map_line = ft_strdup("");
// 	while (1)
// 	{
// 		map_gnl_buff = ft_get_next_line(map_fd);
// 		if (!map_gnl_buff)
// 			break ;
// 		map_line_buff = map_line;
// 		map_line = ft_strjoin(map_line_buff, map_gnl_buff);
// 		free(map_gnl_buff);
// 		free(map_line_buff);
// 	}
// 	close(map_fd);
// 	validate_map(stc, map_line);
// 	map = ft_split(map_line, '\n');
// 	free(map_line);
// 	return (map);
// }

void    exit_error(char *s)
{
    ft_printf("Error\n");
    ft_printf("%s", s);
    exit(0);
    return(0);
}
int	is_newline(t_node *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

bool	check_map_form(t_map *map)
{
    int i;
	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != ft_strlen(game->map.map[i]))
			return (false);
		i += 1;
	}
	return (true);
}

// static bool	is_closed(t_map *map)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < map->rows)
// 		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL)
// 			return (false);
// 	i = -1;
// 	while (++i < map->columns)
// 		if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
// 			return (false);
// 	return (true);
// }

bool	check_walls(t_map *map, int fd)
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
    //horizontal walls
    while (i < map->height)
    {
        //left and right characters
        if (map->body[0][i] != '1' || map->body[map->length - 1][i] != '1')
            return (false);
        i++;
    }
}


bool	check_rectangle(t_map *map)
{
    int i;
    int len;

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
static void	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (!is_onstr(VALID_ENTITIES, game->map.map[i][j]))
				panic(game, INVALID_ENTITY);
			if (game->map.map[i][j] == EXIT)
				game->map.exit += 1;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectibles += 1;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){j, i};
			}
		}
	}
	throw_error_if(game);
}
bool    check_characters(t_map *map)
{
    int x;
    int y;

    x = 0;
    while(x < map->length)
    {
        y = 0;
        while(y < map->height)
        {
            if (map->body[x][y] == 'C')
                map->collectibles++;
            else if (map->body[x][y] == 'E')
                map->exit++
            else if (map->body[x][y] == 'P')
                map->player_pos++
        }
        y++;
    }
}


bool   check_map(t_map *map)
{
    if (check_rectangle(map) == true && check_walls == true && check_characters == true)
        return (true);
}

void   get_map_size(t_map *map, int fd)
{
    int i;
    char *map_line;

    map->length = 0;
    map_line = get_next_line(fd);
    map->length = ft_strlen(map_line);
    map->height = 0;
    while (map_line != NULL)
    {        
        map->height++;
        free(map_line);
        map_line = get_next_line(fd);       
    }
    close(fd);
}

char    read_map(char *path)
{
    int     i;
    int     fd;
    t_map   *map;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        exit_error("The map cannot be opened.");
    // initializing the size of the map
    get_map_size(map, fd);
    // initializing the body of the map
    map->body = NULL;
    map->body = (char **) malloc (sizeof(char *) * (map->height + 1));
    if (map->body == NULL)
        exit_error("Memory Error.");
    i = 0;
    while (i < map->height)
        map->body[i++] = get_next_line(fd);
    //checking if the map is correctly structured
    if (check_map == true)
        return (map);
}

int	main(int argc, char *argv[])
{
    // t_game vars;
	// t_data	img;

    
    if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) != 0)
    {
        // // START GAME
        vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, 1920, 1080, "./so_long");

        //READ MAP
        read_map(argv[1]);
    

        
        // img.img = mlx_new_image(vars.mlx, 1920, 1080);
        // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        //                             &img.endian);
        // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
        // mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
        
        //void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
        // mlx_hook(vars.win, 2, 1L<<0, press_keys, &vars);
        
        // mlx_loop(vars.mlx);
    }
    // else
    // {
    //     ft_printf("Error\n");
    //     ft_printf("The argument entered in the command line is incorrect.");
    //     return (0);
    // }
    return(0);
    
}


// FREE

// mlx_init
// free(xvar);

// mlx_new_window
// free(new_win);

//image
// free(img);