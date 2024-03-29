/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:04 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/29 19:18:13 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "keys.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	char			**body;
	int	cols;
	int	rows;
	int	num_potions;
	int	num_exits;
	int	num_players;
	int exit;
	int collectibles;
	int player_pos;
}				t_map;

typedef struct s_sprite{
	void	*wall;
	int		width;
	int		height;
}				t_sprite;

typedef struct s_graphic {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}				t_graphic;

typedef struct s_game
{
	t_map			*map;	
	t_point			curr;
	t_point			next;
	t_graphic		graphics;
	t_sprite		sprite;
	int	coins;
	int	moves;
}				t_game;


//main.c
int    exit_error(char *s);

//read_map.c
void    read_map(char *path, t_game *game);

//check_map.c
void   check_map(t_game *game);



#endif