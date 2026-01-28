#include "../include/so_long.h"

#include <stdio.h> //for testing
int	read_map(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1 || fd < 0)
		return (print_error("Opening file."));
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return EXIT_SUCCESS;
}
