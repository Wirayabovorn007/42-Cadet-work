
#include "../include/minitalk.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	server_pid;
	char *str;

	if (argc != 3)
		return (1);
	i = 0;
	str = argv[2];
	server_pid = ft_atoi(argv[1]);
	while (str[i])
	{
		send_bit(server_pid, str[i]);
		i++;
	}
	return (0);
}
