/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:42 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/03 18:11:36 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    exit_error(char *s)
{
    ft_printf("Error\n");
    ft_printf("%s", s);
    exit(0);
    return(0);
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
        //FLOOD FILL
        floodfill(&game);
        // LAUNCH GAME
        launch_game(&game);
        // Move Player
        // mlx_key_hook(game.graphics.win, key_hook, &game);
        // mlx_hook(game.graphics.win, ON_KEYDOWN, (1L << 0), play, &game); // ou 2
        // mlx_hook(game.graphics.win, ON_KEYDOWN, (1L << 0), press, &game);
        // mlx_hook(game.graphics.win, ON_DESTROY, (1L<<17), quit_game, &game);
        // mlx_loop_hook(game.graphics.mlx, play, &game);
        // mlx_loop_hook(game.graphics.mlx, &put_images_to_window, &game);
		mlx_key_hook(game.graphics.win, &press, &game);
		mlx_hook(game.graphics.win, 17, (1L << 1), &quit_game, &game);
        mlx_loop(game.graphics.mlx);
    }
    else if (argc != 2)
        exit_error("Invalid number of parameters. ");
    else if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
        exit_error("Invalid file name. ");
    return(0);
}
