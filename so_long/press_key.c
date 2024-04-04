/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:42:14 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/04 15:11:20 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    display_nb_moves(t_game *game)
{
    char	*str;
    
    str = ft_itoa(game->moves);
	mlx_string_put(game->graphics.mlx, game->graphics.win, 10, 32, 0x00FFFFFF, "NB = ");
	mlx_string_put(game->graphics.mlx, game->graphics.win, 40, 32, 0x00FFFFFF, str);
	free(str);
}

void move_player(t_game *game)
{
    // Check if the next position is a wall
    if (game->map->body[game->next.x][game->next.y] == '1')
        return;
    // Store the original sprite of the previous position
    char prev_sprite = game->map->body[game->player_pos.x][game->player_pos.y];
    // Store the sprite of the exit point before updating the map
    char exit_sprite = game->map->body[game->exit_pos.x][game->exit_pos.y];

    // Replace the previous position sprite with its original sprite (except if it was a collectible)
    if (prev_sprite != 'C')
        game->map->body[game->player_pos.x][game->player_pos.y] = (prev_sprite == 'E' && game->coins != game->map->collectibles) ? 'E' : '0';

    // Collect coins and update the map
    if (game->map->body[game->next.x][game->next.y] == 'C')
    {
        game->coins++;
        game->map->body[game->next.x][game->next.y] = '0';
    }
    // Check if the next position is the exit and all coins have been collected
    else if (game->map->body[game->next.x][game->next.y] == 'E' && game->coins == game->map->collectibles)
        quit_game(game);
    // Set the player character in the new position
    game->map->body[game->next.x][game->next.y] = 'P';
    // Restore the sprite of the exit point if not all coins have been collected
    if (game->coins != game->map->collectibles && exit_sprite == 'E')
        game->map->body[game->exit_pos.x][game->exit_pos.y] = 'E';
    // Update the player's position
    game->player_pos = game->next;
    // Render the updated map
    put_images_to_window(game);
    // Update moves
    game->moves++;
}

int	press(int keycode, t_game *game)
{
    game->next = (t_point){game->player_pos.x, game->player_pos.y};
	if (keycode == ESC)
		quit_game(game);
	else if (keycode == W || keycode == UP)
	    game->next = (t_point){game->player_pos.x - 1, game->player_pos.y};
	else if (keycode == A || keycode == LEFT)
		game->next = (t_point){game->player_pos.x, game->player_pos.y - 1};
	else if (keycode == D || keycode == RIGHT)
		game->next = (t_point){game->player_pos.x, game->player_pos.y + 1};
    else if (keycode == S || keycode == DOWN)
		game->next = (t_point){game->player_pos.x + 1, game->player_pos.y};
    move_player(game);
    display_nb_moves(game);
	return (0);
}