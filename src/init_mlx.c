#include "../includes/cub3d.h"

int	init_mlx(t_cub *cub)
{
	cub->mlx_s.mlx = mlx_init();
	cub->mlx_s.window = mlx_new_window(cub->mlx_s.mlx, WWIDTH, WHEIGHT, "Cub");
	mlx_key_hook(cub->mlx_s.window, key_pressed, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
	return (0);
}
