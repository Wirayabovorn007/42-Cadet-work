#include "../include/so_long.h"

void	init_game(char **map,char *path)
{
	void	*mlxptr;
	void	*winptr;
	int		height;
	int		width;

	mlxptr = mlx_init();
	if (mlxptr == NULL)
		return ;
	height = get_line_count(path);
	width = len(map[0]);
	winptr = mlx_new_window(mlxptr, 64 * width,64 * height, "./so_long");
	if (winptr == NULL)
		return ;
	mlx_loop(mlxptr);
	free(map);
}
