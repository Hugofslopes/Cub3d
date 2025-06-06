/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:39:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 17:56:33 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_exit_keys(t_cub *cub)
{
	free(cub->map);
	free(cub->textures);
	exit(1);
}

void	free_exit_textures(t_cub *cub)
{
	free(cub->textures);
	exit(1);
}

void	free_config(t_config *cfg)
{
	free(cfg->no_path);
	free(cfg->so_path);
	free(cfg->we_path);
	free(cfg->ea_path);
	ft_bzero(cfg, sizeof(*cfg));
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_exit(t_cub *cub, int value)
{
	size_t	i;

	i = 0;
	mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
	while (i < 4)
		mlx_destroy_image(cub->mlx_s.mlx, cub->texture[i++].img);
	i = 0;
	free_map(cub->map);
	while (i < 10)
		mlx_destroy_image(cub->mlx_s.mlx, cub->keys[i++].img);
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free_config(&cub->config);
	free_map(cub->textures);
	free(cub->mlx_s.mlx);
	exit(value);
}
