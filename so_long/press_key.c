/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:42:14 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/03 18:12:52 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	up(t_game *game)
// {
// 	if (game->map->body[game->player_pos.y + 1][game->player_pos.x] != '1')
// 	{
// 		if (game->map->body[game->player_pos.y + 1][game->player_pos.x] != 'E'  && game->coins != game->map->collectibles)
// 		{
// 			game->map->body[game->player_pos.y][game->player_pos.x] = '0';
// 			game->map->body[game->player_pos.y + 1][game->player_pos.x] = 'P';
// 		}
// 		else if (game->map->body[game->player_pos.y + 1][game->player_pos.x] == 'E'
// 			&& game->coins == game->map->collectibles)
// 			quit_game(game);
// 		game->moves++;
// 	}
// }

// void	down(t_game *game)
// {
// 	if (game->map->body[game->player_pos.y - 1][game->player_pos.x] != '1')
// 	{
// 		if (game->map->body[game->player_pos.y - 1][game->player_pos.x] != 'E'
// 			&& game->coins != game->map->collectibles)
// 		{
// 			game->map->body[game->player_pos.y][game->player_pos.x] = '0';
// 			game->map->body[game->player_pos.y - 1][game->player_pos.x] = 'P';
// 		}
// 		else if (game->map->body[game->player_pos.y - 1][game->player_pos.x] == 'E'
// 			&& game->coins == game->map->collectibles)
// 			quit_game(game);
// 		game->moves++;
// 	}
// }

// void	right(t_game *game)
// {

// 	if (game->map->body[game->player_pos.y][game->player_pos.x + 1] != '1')
// 	{
// 		if (game->map->body[game->player_pos.y][game->player_pos.x + 1] != 'E'
// 			&& game->coins != game->map->collectibles)
// 		{
// 			game->map->body[game->player_pos.y][game->player_pos.x] = '0';
// 			game->map->body[game->player_pos.y][game->player_pos.x + 1] = 'P';
// 		}
// 		else if (game->map->body[game->player_pos.y][game->player_pos.x + 1] == 'E'
// 			&& game->coins == game->map->collectibles)
// 			quit_game(game);
// 		game->moves++;
// 	}
// }

// void	left(t_game *game)
// {
// 	if (game->map->body[game->player_pos.y][game->player_pos.x - 1] != '1')
// 	{
// 		if (game->map->body[game->player_pos.y][game->player_pos.x - 1] != 'E'
// 			&& game->coins != game->map->collectibles)
// 		{
// 			game->map->body[game->player_pos.y][game->player_pos.x] = '0';
// 			game->map->body[game->player_pos.y][game->player_pos.x - 1] = 'P';
// 		}
// 		else if (game->map->body[game->player_pos.y][game->player_pos.x - 1] == 'E'
// 			&& game->coins == game->map->collectibles)
// 			quit_game(game);
// 		game->moves++;
// 	}
// }

void    move_player(t_game *game)
{
    //if we move on a wall
    if (game->map->body[game->next.x][game->next.y] == '1')
        return ;
    //update what we move from
    if (game->map->body[game->player_pos.x][game->player_pos.y] == 'E')
        mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.exit, 32 * game->player_pos.y, 32 * game->player_pos.x);
    else
        mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.empty, 32 * game->player_pos.y, 32 * game->player_pos.x);
    //collect coins
    if (game->map->body[game->next.x][game->next.y] == 'C')
        game->coins++;
    else if (game->map->body[game->next.x][game->next.y] == 'E' && game->coins == game->map->collectibles)
        quit_game(game);
    //update moves
    game->moves++;
    //update player pos
    game->map->body[game->next.x][game->next.y] = 'P';
    mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.player, 32 * game->next.y, 32 * game->next.x);
    game->player_pos = game->next;
}


int	press(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit_game(game);
	else if (keycode == W || keycode == UP)
	    game->next = (t_point){game->player_pos.x - 1, game->player_pos.y};
	else if (keycode == A || keycode == LEFT)
		game->next = (t_point){game->player_pos.x, game->player_pos.y - 1};
	else if (keycode == D || keycode == RIGHT)
		game->next = (t_point){game->player_pos.x, game->player_pos.y + 1};
    else if (keycode == S || keycode == DOWN)
		game->next = (t_point){game->player_pos.x + 1, game->player_pos.y + 1};
    move_player(game);
	return (0);
}


// int	press(int keycode, t_game *game)
// {
// 	if (keycode == W || keycode == UP)
// 	    up(game);
// 	else if (keycode == S || keycode == DOWN)
//         down(game);
// 	else if (keycode == D || keycode == RIGHT)
//         right(game);
// 	else if (keycode == A || keycode == LEFT)
//         left(game);
// 	else if (keycode == ESC)
// 		quit_game(game);
// 	return (0);
// }

// void    move_player(t_game *game)
// {
//     //if we move on a wall
//     if (game->map->body[game->next.x][game->next.y] == '1')
//         return ;
//     //update what we move from
//     if (game->map->body[game->player_pos.x][game->player_pos.y] == 'E')
//         mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.exit, 32 * game->player_pos.y, 32 * game->player_pos.x);
//     else
//         mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.empty, 32 * game->player_pos.y, 32 * game->player_pos.x);
//     //collect coins
//     if (game->map->body[game->next.x][game->next.y] == 'C')
//         game->coins++;
//     else if (game->map->body[game->next.x][game->next.y] == 'E' && game->coins == game->map->body->collectibles)
//         quit_game(game);
//     //update moves
//     game->moves++;
//     //update player pos
//     game->map->body[game->next.x][game->next.y] = 'P';
//     mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.player, 32 * game->next.y, 32 * game->next.x);
//     game->player_pos = game->next;
// }

