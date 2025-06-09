#include "../includes/cub3d.h"

int	handle_input(int ac, char **av, t_cub *cub)
{
	int	fd;

	if (ac != 2)
		return (ft_printf_fd(2,"%s%s", ERROR, ARGNB));
	if (open_scene_file(av[1], &fd))
		return (1);
	if (parse_scene_file(&fd, cub))
	{
		close(fd);
		free_config(&cub->config);
		return (1);
	}
	close(fd);
	return (0);
}
