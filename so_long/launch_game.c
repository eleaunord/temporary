/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:30:25 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/03 18:11:14 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
            if (game->map->body[x][y] == 'C')
                mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.collectibles, 32 * y, 32 * x);
            else if (game->map->body[x][y] == 'E')
               mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.exit, 32 * y, 32 * x);
            else if (game->map->body[x][y] == 'P')
                mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.player, 32 * y, 32 * x);
            else if (game->map->body[x][y] == '1')
                mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.wall, 32 * y, 32 * x);
            else if (game->map->body[x][y] == '0')
                mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.empty, 32 * y, 32 * x);
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
    game->sprite.collectibles = malloc(sizeof(void *));
    game->sprite.player = malloc(sizeof(void *));
    game->sprite.exit = malloc(sizeof(void *));
    game->sprite.empty = malloc(sizeof(void *));
    if (!game->sprite.wall || !game->sprite.collectibles || !game->sprite.player || !game->sprite.exit || !game->sprite.empty)
		 exit_error("Failed sprite allocation. ");
    game->sprite.wall = mlx_xpm_file_to_image(game->graphics.mlx, "./images/wall.xpm", &img_width, &img_cols);
    game->sprite.collectibles = mlx_xpm_file_to_image(game->graphics.mlx, "./images/collectibles.xpm", &img_width, &img_cols);
    game->sprite.exit = mlx_xpm_file_to_image(game->graphics.mlx, "./images/exit.xpm", &img_width, &img_cols);
    game->sprite.player = mlx_xpm_file_to_image(game->graphics.mlx, "./images/player.xpm", &img_width, &img_cols);
    game->sprite.empty = mlx_xpm_file_to_image(game->graphics.mlx, "./images/empty.xpm", &img_width, &img_cols);
    if (!game->sprite.wall || !game->sprite.collectibles || !game->sprite.player || !game->sprite.exit || !game->sprite.empty)
		 exit_error("Failed xpm allocation. ");
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
    game->graphics.win = mlx_new_window(game->graphics.mlx, game->map->cols * 32, game->map->rows * 32, "./so_long");
    if (!game->graphics.win)
    {
        // free(new_win);
        exit_error("There is a problem with initializing the game window. ");
    }
    launch_graphics(game);
} 
