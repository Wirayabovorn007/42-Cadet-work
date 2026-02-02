#include "../include/so_long.h"

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

int	validmap_cond3(char **map)
{
	int	i;
	int	j;
	int	cnt[3];

	i = -1;
	ft_bzero(cnt, sizeof(int) * 3);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("01CEP", map[i][j]))
				return (0);
			if (map[i][j] == 'P')
				cnt[0]++;
			else if (map[i][j] == 'E')
				cnt[1]++;
			else if (map[i][j] == 'C')
				cnt[2]++;
		}
	}
	return (cnt[0] == 1 && cnt[1] == 1 && cnt[2] >= 1);
}

int	validmap_cond4(char *line)
{
	int	f;
	int	l;
	int	i;

	i = -1;
	f = 0;
	l = 0;
	if (line[0] == '1')
		f = 1;
	while (line[++i] != '\0')
		;
	if ((i > 0) && (line[i - 1] == '1'))
		l = 1;
	return (f && l);
}

int	is_valid_file_path(char *path)
{
	int	len_path;

	len_path = len(path);
	if (len_path < 4)
		return (-1);
	if (ft_strlcmp(path + len_path - 4, ".ber", 4) != 0)
		return (-1);
	return (1);
}

char	**closefd_w_err(int fd, char *t)
{
	close(fd);
	return (map_err(t));
}
