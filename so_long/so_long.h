/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:04 by eleroty           #+#    #+#             */
/*   Updated: 2024/03/27 17:47:22 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "keys.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
    
}				t_game;

typedef struct	s_map {
    char **body;
    int length;
    int height;
    int     collectibles;
    int     exit;
    int player_pos;
}				t_map;

typedef struct	s_images {


}				t_images;

#endif