#include "../includes/cub3d.h"

int	handle_input(int ac, char **av, t_cub *cub)
{
	int	fd;

	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), 1);
	if (open_scene_file(av[1], &fd))
	{
		printf("Inside open_scene_file call\n");
		return (1);
	}
	printf("Moving on to parse_scene_file\n");
	if (parse_scene_file(&fd, cub))
	{
		close(fd);
		free_config(&cub->config);
		return (1);
	}
	//free_config(&cub->config);	
	printf("Moving on to open_scene_file\n");
	close(fd);
	return (0);
}
