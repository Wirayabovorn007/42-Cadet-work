#include "../include/so_long.h"

void	print_err(char *err)
{
	write(2, "Error\n", 6);
	if (err)
	{
		write(2, "Type: ", 6);
		write(2, err, len(err));
	}
	write(2, "\n", 1);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
