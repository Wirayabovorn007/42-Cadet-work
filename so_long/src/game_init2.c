#include "../include/so_long.h"

void	err_free(char **arr)
{
	free_arr(arr);
	return ;
}

int	get_map_height(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

void	set_player(t_game *game, int row, int col)
{
	game->player.x = col;
	game->player.y = row;
	game->player.collect = 0;
}
