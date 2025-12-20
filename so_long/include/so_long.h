
#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 42
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct player
{
	int	x;
	int	y;
} t_player;

int	start_game();
int	print_err();
int	ft_strlen(char *str);
int	read_map(const char *filename);

#endif