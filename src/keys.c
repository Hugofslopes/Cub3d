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
		cub->t_player.move_u = 1;
	else if (key == 'a' || key == 'A')
		cub->t_player.move_l = 1;
	else if (key == 's' || key == 'S')
		cub->t_player.move_d = 1;
	else if (key == 'd' || key == 'D')
		cub->t_player.move_r = 1;
	else if (key == 65361)
		cub->t_player.rot_l = 1;
	else if (key == 65363)
		cub->t_player.rot_r = 1;
	return (0);
}
