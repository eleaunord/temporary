/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:41:04 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/28 12:09:40 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void)
{
    t_map   map;
    
    map.body = NULL;
    map.length = 0;
    map.height = 0;
    map.collectibles = 0;
    map.exit = 0;
    map.player_pos = 0;

    return(map);
    
}

t_game	init_game(void)
{
    t_game   game;
    
    game.mlx = NULL;
    game.collectibles = 0;
    game.exit = 0;
    game.player_pos = 0;

    return(game);
    
}