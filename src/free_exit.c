#include "../includes/cub3d.h"

void	free_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free(cub->mlx_s.mlx);
	free_config(&cub->config);
	free_map(cub->map);
}

void	free_config(t_config *cfg)
{
	//(void)cfg;
	free(cfg->no_path);
	free(cfg->so_path);
	free(cfg->we_path);
	free(cfg->ea_path);
	ft_bzero(cfg, sizeof(*cfg));
}
