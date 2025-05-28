#include "../includes/cub3d.h"

void	free_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free(cub->mlx_s.mlx);
}

/*void	free_config(t_config *cfg)
{
	(void)cfg;
	free(cfg->no_path);
	free(cfg->so_path);
	free(cfg->we_path);
	free(cfg->ea_path);
	free(cfg->floor_color_set);
	free(cfg->ceiling_color_set);
}*/

void  free_config(t_config *cfg)
{
    free(cfg->no_path);          cfg->no_path          = NULL;
    free(cfg->so_path);          cfg->so_path          = NULL;
    free(cfg->we_path);          cfg->we_path          = NULL;
    free(cfg->ea_path);          cfg->ea_path          = NULL;
    free(cfg->floor_color_set);  cfg->floor_color_set  = NULL;
    free(cfg->ceiling_color_set);cfg->ceiling_color_set= NULL;
}
