#include "../includes/cub3d.h"

char    **test_Array(t_cub *cub);

void	init_player_angle(t_cub *cub)
{
	if (cub->player.start_position == 'E')
		cub->player.angle = 3 * PI / 2;  
	if (cub->player.start_position == 'W')
		cub->player.angle = PI / 2;
	if (cub->player.start_position == 'S')
		cub->player.angle = 0;
	if (cub->player.start_position == 'N')
		cub->player.angle = PI;
}

void	init(t_cub *cub)
{
	cub->game.gamestarted = 0;
	cub->map = test_Array(cub);
	init_player_angle(cub);
	init_mlx(cub);
	init_textures(cub, 0);
	mlx_loop_hook(cub->mlx_s.mlx, build_next_frame, cub);
	mlx_hook(cub->mlx_s.window, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
}
