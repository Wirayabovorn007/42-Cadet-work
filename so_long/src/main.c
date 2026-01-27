
#include "../include/so_long.h"

int	main(void)
{
	int	status;

	status = read_map("../maps/map.ber");
	if (status == EXIT_FAILURE)
		return EXIT_FAILURE;
}
