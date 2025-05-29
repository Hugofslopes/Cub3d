#include "../includes/cub3d.h"

int	mouse_close(t_cub *cub)
{
	free_exit(cub);
	exit(0);
	return (0);
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == 65307)
	{
		free_exit(cub);
		exit(0);
	}
	else if (key == 'w' || key == 'W')
		move_forward(cub);
	else if (key == 'a' || key == 'A')
		move_left(cub);
	else if (key == 's' || key == 'S')
		move_back(cub);
	else if (key == 'd' || key == 'D')
		move_right(cub);
	else if (key == 65361)
		rotate_left(cub);
	else if (key == 65363)
		printf("angle- %f \n", cub->player.angle),	rotate_right(cub);
	return (0);
}
