

# ifndef SO_LONG_H
# define SO_LONG_H

#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./get_next_line.h"

int	read_map(char *path);
int	print_error(char *type);

#endif