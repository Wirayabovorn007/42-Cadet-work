#include "../include/so_long.h"

void	init_game(char **map)
{
	void	*mlxptr;
	void	*winptr;

	mlxptr = mlx_init();
	winptr = mlx_new_window(mlxptr, 640, 480, "./so_long");
	mlx_loop(mlxptr);
}