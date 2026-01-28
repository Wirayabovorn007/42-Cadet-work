#include "../include/so_long.h"

int	get_line_count(char *path)
{
	int		lc;
	int		fd;
	char	*line;

	lc = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		lc++;
		free(line);
	}
	close(fd);
	return (lc);
}

char	**map_err(char *type)
{
	write(2,"Error\n", 6);
	if (type)
	{
		write(1, "Type: ", 2);
		write(2, type, len(type));
	}
	write(2, "\n", 1);
	return NULL;
}

int	validmap_cond3(char *line)
{
	int	f;
	int	l;
	int	i;

	i = -1;
	if (line[0] == '1')
		f = 1;
	while (line[++i] != '\0')
		;
	if (line[i - 1] == '1')
		l = 1;
	return (f && l);
}

int	validmap_cond1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}
char **validate_map(char **arr, int line_count)
{
	char	**t;
	int		row;
	int		col;
	int		len_fline;

	t = arr;
	row = 0;
	col = 0;
	len_fline = len(arr[row]);
	if ((validmap_cond1(arr[0]) != 1) || (validmap_cond1(arr[line_count - 1]) != 1)) // the first and last line must include only wall (1)
		return map_err("Invalid line format.");
	while (arr[row])
	{
		if (len(arr[row]) != len_fline) // all lines must have the same length
			return (map_err("Invalid line length."));
		if (validmap_cond3(arr[row]) != 1) // first and last char of every line must be 1
			return (map_err("Invalid line format."));
		while (arr[col])
		{
			col++;
		}
		row++;
	}

	// map must contain 1 == exit, 1 == starting point, at least 1 >= collectible
}

char	**read_map(char *path)
{
	int		fd;
	int		i;
	int		line_count;
	char	*line;
	char	**line_arr;

	fd = open(path, O_RDONLY);
	line_count = get_line_count(path);
	if (fd < 0 || line_count < 0)
		return (map_err("Opening file."));
	i = 0;
	line_arr = malloc(sizeof(char *) * (line_count + 1));
	if (!line_arr)
		return (map_err("Memory allocation."));
	while ((line = get_next_line(fd)) != NULL)
		line_arr[i++] = line;
	line_arr[i] = NULL;
	close(fd);
	return (validate_map(line_arr, line_count));
}
