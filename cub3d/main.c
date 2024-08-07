#include "cub3d.h"

int send_error(char *details, int status)
{

}

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (send_error("Invalid number of parameters.", 1));
	init_game(&game);
	if (parse_args(&game, av) != 0)
		return (1);
	init_mlx(&game);
	init_textures(&game);
	print_controls();
	render_images(&game);
	listen_for_input(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}