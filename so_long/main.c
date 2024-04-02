/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:42 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/02 18:37:30 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

void    move_player(t_game *game, bool left_or_right, int move)
{

    if (left_or_right)
    {
        if (game->map->body[game->player_pos.y][game->player_pos.x + move] == '1')
            return ;
        if (game->map->body[game->player_pos.y][game->player_pos.x] == 'E')
            mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.exit, game->player_pos.x * 32, game->player_pos.y * 32);
        else
             mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.empty, game->player_pos.x * 32, game->player_pos.y * 32);
        game->player_pos.x += move;
    }
    else
    {
        if (game->map->body[game->player_pos.y + move][game->player_pos.x] == '1')
            return ;
        if (game->map->body[game->player_pos.y][game->player_pos.x] == 'E')
            mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.exit, game->player_pos.x * 32, game->player_pos.y * 32);
        else
             mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.empty, game->player_pos.x * 32, game->player_pos.y * 32);
        game->player_pos.y += move;
    }
    if (game->map->body[game->player_pos.y][game->player_pos.x] == 'C')
    {
        game->map->body[game->player_pos.y][game->player_pos.x] = '0';
        game->coins++;
        return ;
    }
    if (game->map->body[game->player_pos.y][game->player_pos.x] == 'E' && game->coins == game->map->collectibles)
        quit_game(game);
    game->moves++;
    mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->sprite.player, game->player_pos.x * 32, game->player_pos.y * 32);
}

int	press(int keycode, t_game *game)
{
    if (keycode == UP || keycode == W)
        move_player(game, false, -1); // y + 1
    if (keycode == DOWN || keycode == S)
        move_player(game, false, 1); // y - 1
    if (keycode == LEFT || keycode == A)
        move_player(game, true, -1); // x - 1
    if (keycode == RIGHT || keycode == D)
        move_player(game, true, 1); // x + 1
    return (0);
}

// int key_hook(int keycode, t_game *game)
// {
//     if (!game)
//         exit_error("Memory error. ");
//     if (press(keycode, game))
//     {
//         game->moves++;
//         ft_printf("Steps : ");
//         ft_putnbr(game->moves);
//         ft_printf("\n");
//     }
//     // if (keycode == 53) == ESC
//     return (0);
        
// }
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

// void	put_player_tile(t_game *game)
// {
// 	char	*moves_str;

// 	game->moves += 1;
// 	mlx_put_image_to_window(game->graphics.mlx, game->win_ptr, game->sprite.player,
// 		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
// 	mlx_put_image_to_window(game->graphics.mlx, game->win_ptr,
// 		game->sprite.wall, 0, 0);
// 	moves_str = ft_itoa(game->moves);
// 	mlx_string_put(game->graphics.mlx, game->win_ptr, 32, 10, 1, moves_str);
// 	free(moves_str);
// }


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
        // Move Player
        // mlx_key_hook(game.graphics.win, key_hook, &game);
        // mlx_hook(game.graphics.win, ON_KEYDOWN, (1L << 0), play, &game); // ou 2
        mlx_hook(game.graphics.win, ON_KEYDOWN, (1L << 0), press, &game);
        mlx_hook(game.graphics.win, ON_DESTROY, (1L<<17), quit_game, &game);
        // mlx_loop_hook(game.graphics.mlx, render_frame, &game);
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