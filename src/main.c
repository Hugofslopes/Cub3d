#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (handle_input(ac, av, &cub))
		return (1);
	init(&cub);
	return (0);
}
