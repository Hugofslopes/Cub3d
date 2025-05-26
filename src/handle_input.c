#include "../includes/cub3d.h"

int	handle_input(int ac, char **av, t_cub *cub)
{
	int	fd;

	(void)cub;
	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), 1);
	if (open_scene_file(av[1], &fd))
		return (1);
	return (0);
}
