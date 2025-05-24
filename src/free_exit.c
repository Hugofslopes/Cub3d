#include "../includes/cub3d.h"

void	free_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free(cub->mlx_s.mlx);
}
