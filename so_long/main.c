/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:42 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/04 15:12:35 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
    t_game  game;
    
    if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) != 0)
    {   
        // INITIALIZE GAME
        ft_bzero(&game, sizeof(t_game));
        //READ MAP
        read_map(argv[1], &game);
        //FLOOD FILL
        floodfill(&game);
        // LAUNCH GAME
        launch_game(&game);
        // Move Player
		mlx_key_hook(game.graphics.win, &press, &game);
		mlx_hook(game.graphics.win, 17, (1L << 1), &quit_game, &game);
        mlx_loop(game.graphics.mlx);
    }
    else if (argc != 2)
        exit_error("Invalid number of parameters. ", &game);
    else if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
        exit_error("Invalid file name. ", &game);
    return(0);
}
