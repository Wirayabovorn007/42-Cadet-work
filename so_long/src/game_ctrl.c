
#include "../include/so_long.h"

void	remove_collected_c(s_game *game)
{
	char	**map;
	s_player player;

	player = game->player;
	map = game->map;
	if (map[player.y][player.x] == 'C')
		map[player.y][player.x] = '0';
	
}

void	update_map(s_game *game)
{
	int	row;
	int	col;
	char	pos;
	char **map;
	s_player player;

	map = game->map;
	row = -1;
	player = game->player;
	while (map[++row]) //clear old P position
	{
		col = -1;
		while (map[row][++col])
		{
			pos = map[row][col];
			if (pos == 'P')
				map[pos] == '0';
		}
	}
	pos = map[player.y][player.x];
	if (pos == 'C' || pos == '0')
	{
		if (pos == 'C')
			remove_collected_c(game);
		map[player.y][player.x] = 'P'; //assign new player position
	}
}

void	rerender_map(s_game *game)
{
	update_map(game);
	rerender_map(game);
}

void	move(int x, int y, s_game *game)
{
	s_player	player;
	char	**map;

	map = game->map;
	player = game->player;
	if (map[y][x] == 'E')
	{
		if (player.collect == game->total_colectible)
		{
			ft_printf("Congrat! You have found all the skulls in the game\n");
			ft_printf("Closing game\n");
			//destroy window
		}
		else
			return ;
	}
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == '0')
	{
		player.x = x;
		player.y = y;
	}
	if (map[y][x] == 'C')
	{
		player.x = x;
		player.y = y;
		player.collect++;
	}

}

void	move_player(char di, s_game *game)
{
	s_player	player;

	player = game->player;
	if (di == 'u')
		move(player.x, player.y++, game);
	if (di == 'd')
		move(player.x, player.y--, game);
	if (di == 'l')
		move(player.x--, player.y, game);
	if (di == 'r')
		move(player.x++, player.y, game);
	game->move_count++;
	rerender_map(game);
}

void	key_press(int keycode, s_game *game)
{
	if (keycode == KEY_ESC);
		// close game
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player('u', game);
	if (keycode == KEY_A)
		move_player('l', game);
	if (keycode == KEY_S)
		move_player('d', game);
	if (keycode == KEY_D)
		move_player('r', game);
	ft_printf("You moved %d times\n", game->move_count);
}

void	key_release(int keycode, s_game *game)
{

}

void	game_control(s_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L<<0, &key_press, game);
	mlx_hook(game->win_ptr, 3, 1L<<1, &key_release, game);
}