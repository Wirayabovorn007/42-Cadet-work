
#include "../include/minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 1)
		return (1);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, bit_to_str);
		signal(SIGUSR2, bit_to_str);
		pause();
	}
	return (0);
}