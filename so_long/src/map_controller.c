#include "../include/so_long.h"

#include <stdio.h> //for testing
int	read_map(char *path)
{
	int	fd;
	ssize_t bytes_read;
	char *buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error("Opening file."));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (print_error("Memory allocation."));
	int i=0;
	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		
		buffer[bytes_read] = '\0';
		printf("Line %d: %s\n", i++, buffer);
	}
	if (bytes_read == -1)
		return (print_error("Reading file."));
	if (close(fd) == -1)
		return (print_error("Cloding file."));
	free(buffer);
	return EXIT_SUCCESS;
}
