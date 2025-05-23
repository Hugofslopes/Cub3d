#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	
	cub.map = malloc(sizeof(char *) * 10);
	free(cub.map);
	(void)ac;
	(void)av;
}
