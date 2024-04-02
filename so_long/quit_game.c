/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:51 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/02 16:46:38 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

void	free_map(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->map->body)
		return ;
	while (game->map->body[i])
	{
		free(game->map->body[i]);
		game->map->body[i] = NULL;
		i++;
	}
	if (i > 0)
		free(game->map->body);
	game->map->body = NULL;
}

void	destroy_sprites(t_game *game)
{
	if (game->sprite.wall)
		mlx_destroy_image(game->graphics.mlx, game->sprite.wall);
	if (game->sprite.player)
		mlx_destroy_image(game->graphics.mlx, game->sprite.player);
	if (game->sprite.collectibles)
		mlx_destroy_image(game->graphics.mlx, game->sprite.collectibles);
	if (game->sprite.exit)
		mlx_destroy_image(game->graphics.mlx, game->sprite.exit);
}

int    quit_game(t_game *game)
{
    if (!game)
        return (0);
    destroy_sprites(game);
    if (game->map->body)
        free_map(game);
    if (game->graphics.mlx)
    {
        mlx_destroy_display(game->graphics.mlx);
        free(game->graphics.mlx);
    }
    if (game->graphics.win)
        mlx_destroy_window(game->graphics.mlx, game->graphics.win);
    return (0);
}
