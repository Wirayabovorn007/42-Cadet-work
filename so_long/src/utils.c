
#include "../include/so_long.h"

int len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	print_error(char *type)
{
	write(2,"Error\n", 6);
	if (type)
	{
		write(1, "Type: ", 2);
		write(2, type, len(type));
	}
	write(2, "\n", 1);
	return EXIT_FAILURE;
}

char *ft_strjoin(char *src, char *to_join)
{
	
}