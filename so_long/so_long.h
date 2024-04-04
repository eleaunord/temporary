/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:04 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/04 14:46:50 by eleroty          ###   ########.fr       */
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
	void	*collectibles;
	void	*player;
	void	*empty;
	void	*exit;
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
	t_point			player_pos;
	t_point			exit_pos;
	t_point			next;
	t_graphic		graphics;
	t_sprite		sprite;
	void	*wall;	
	void	*collectibles;
	void	*player;
	void	*empty;
	void	*exit;
	int	coins;
	int	moves;
	int	flag;
}				t_game;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

//main.c
int	main(int argc, char *argv[]);
void    exit_error(char *s, t_game *game);
// int	press(int keycode, t_game *game);
// void    move_player(t_game *game, bool left_or_right, int move);
void	move_player(t_game *game);
int	press(int keycode, t_game *game);

//read_map.c
void    read_map(char *path, t_game *game);
t_map	*map_new(int cols, int rows);
int	get_num_lines(char *path, t_game *game);
char	*trim(char const *s1, char const *set);


//check_map.c
void   check_map(t_game *game);
int	get_len(const char *s);
bool	check_rectangle(t_game *game);

bool	check_path(t_game *game);
void	floodfill(t_game *game);

//quit
int    quit_game(t_game *game);
void	free_map(t_game *game);
void	destroy_sprites(t_game *game);

//launch
void    launch_game(t_game *game);
void    put_images_to_window(t_game *game);
void    launch_graphics(t_game *game);

#endif