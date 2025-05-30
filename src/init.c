#include "../includes/cub3d.h"

char    **test_Array(t_cub *cub);

void init_player_angle(t_cub *cub)
{
    if (cub->player.start_position == 'N')
        cub->player.angle = 270.0;
    else if (cub->player.start_position == 'S')
        cub->player.angle = 90.0;
    else if (cub->player.start_position == 'E')
        cub->player.angle = 0.0;
    else if (cub->player.start_position == 'W')
        cub->player.angle = 180.0;
}


void	init_keys(t_cub *cub, size_t i){
	char *key[] = {
    "keys/w.xpm",
    "keys/s.xpm",
    "keys/a.xpm",
    "keys/d.xpm",
	"keys/base.xpm",
	"keys/rl.xpm",
	"keys/rr.xpm",
	"keys/rlf.xpm",
	"keys/b.xpm",
	"keys/nb.xpm"
};

	while (i < 10)
	{
		cub->keys[i].img = mlx_xpm_file_to_image(cub->mlx_s.mlx, \
		key[i], &cub->keys[i].width, &cub->keys[i].height);
		cub->keys[i].addr = mlx_get_data_addr(cub->keys[i].img, \
		&cub->keys[i].bytes_p_pixel, &cub->keys[i].line_len, \
		&cub->keys[i].endian);
		i++;
	}
}

void	init(t_cub *cub)
{
	cub->game.gamestarted = 0;
	cub->game.cellsize = 3;
	cub->player.speed = 0.3;
	cub->map = test_Array(cub);
	init_player_angle(cub);
	init_mlx(cub);
	init_keys(cub, 0);
	init_textures(cub, 0);
	mlx_loop_hook(cub->mlx_s.mlx, build_next_frame, cub);
	mlx_hook(cub->mlx_s.window, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
}
