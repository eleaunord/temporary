/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:42 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/29 19:10:01 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// create 2 or more images to hold frames + one tmp

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_rows + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// t_game	init_game(void)
// {
//     t_game   game;
    
//     game->mlx = NULL;
//     game.collectibles = 0;
//     game.exit = 0;
//     game.player_pos = 0;

//     return(game);
    
// }

// int	close_window(t_game *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int press_keys(int keycode, void *vars)
// {
//     if (keycode == ESC)
//         close_window(vars);
//     return (0);
// }

int    exit_error(char *s)
{
    ft_printf("Error\n");
    ft_printf("%s", s);
    exit(0);
    return(0);
}


void    check_xpm(t_game *game)
{
    if (!game->sprite.wall)
        exit_error("The reading of the wall image has failed. ");
}
// void	put_player_tile(t_game *game)
// {
// 	char	*moves_str;

// 	game->moves += 1;
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
// 		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
// 		game->tiles.wall, 0, 0);
// 	moves_str = ft_itoa(game->moves);
// 	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 10, 1, moves_str);
// 	free(moves_str);
// }


void    put_images_to_window(t_game *game)
{
    int x;
    int y;

    x = 0;
    while(x < game->map->rows)
    {
        y = 0;
        while(y < game->map->cols)
        {
            // if (map->body[x][y] == 'C')
            //     mlx_put_image_to_window(game->mlx, game->win, game->collectibles, 32 * x, 32 * y);
            // else if (map->body[x][y] == 'E')
            //     mlx_put_image_to_window(game->mlx, game->win, game->exit, 32 * x, 32 * y);
            // else if (map->body[x][y] == 'P')
            //     mlx_put_image_to_window(game->mlx, game->win, game->player_pos, 32 * x, 32 * y);
            if (game->map->body[x][y] == '1')
                mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.wall, 32 * x, 32 * y);
            y++;
        }
        x++;
    }
}

void    launch_graphics(t_game *game)
{
    int		img_width;
	int		img_cols;

    img_width = 32;
    img_cols = 32;
    game->sprite.wall = malloc(sizeof(void *));
    if (!game->sprite.wall)
		 exit_error("Failed sprite allocation. ");
    game->sprite.wall = mlx_xpm_file_to_image(game->graphics.mlx, "./images/wall.xpm", &img_width, &img_cols);
    // game->collectibles = mlx_xpm_file_to_image(game->mlx, "./images/collectibles.xpm", &img_width, &img_cols);
    // game->exit = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &img_width, &img_cols);
    // game->player_pos = mlx_xpm_file_to_image(game->mlx, "./images/player_pos.xpm", &img_width, &img_cols);
    check_xpm(game);
    put_images_to_window(game);
}

void    launch_game(t_game *game)
{
    // //init game ou calloc?
    // ft_bzero(game, sizeof(t_game));
    game->graphics.mlx = mlx_init();
    if (!game->graphics.mlx)
    {
        // free(xvar);
        exit_error("There is a problem with initializing the minilibx. ");
    }
    game->graphics.win = mlx_new_window(game->graphics.mlx, game->map->rows * 32, game->map->cols * 32, "./so_long");
    if (!game->graphics.win)
    {
        // free(new_win);
        exit_error("There is a problem with initializing the game window. ");
    }
    launch_graphics(game);
} 


int	main(int argc, char *argv[])
{
    t_game  game;
    
    if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) != 0)
    {   
        // INITIALIZE GAME
        ft_bzero(&game, sizeof(t_game));
        // ft_bzero(&map, sizeof(t_map));
        // game = init_game();
        // map = init_map();
        //READ MAP
        read_map(argv[1], &game);
        // LAUNCH GAME
        launch_game(&game);
        mlx_loop(game.graphics.mlx);
    }
    else if (argc != 2)
        exit_error("Invalid number of parameters. ");
    else if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
        exit_error("Invalid file name. ");
    return(0);
}

// FREE

// mlx_init
// free(xvar);

// mlx_new_window
// free(new_win);

//image
// free(img);