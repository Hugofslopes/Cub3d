/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:39:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/09 11:07:39 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_exit_keys(t_cub *cub, size_t i, int flag)
{
	size_t	j;

	j = 0;
	if (flag)
	{
		while (j < i)
			mlx_destroy_image(cub->mlx_s.mlx, cub->keys[j++].img);
	}
	mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free_array(cub->map);
	free_array(cub->map_copy);
	free_array(cub->textures);
	free_config(&cub->config);
	free(cub->mlx_s.mlx);
	exit(1);
}

void	free_exit_textures(t_cub *cub, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		mlx_destroy_image(cub->mlx_s.mlx, cub->texture[j++].img);
	i = 0;
	while (i < 11)
		mlx_destroy_image(cub->mlx_s.mlx, cub->keys[i++].img);
	mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free_array(cub->map);
	free_array(cub->map_copy);
	free_array(cub->textures);
	free_config(&cub->config);
	free(cub->mlx_s.mlx);
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

void	free_array(char **map)
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
	free_array(cub->map);
	while (i < 11)
		mlx_destroy_image(cub->mlx_s.mlx, cub->keys[i++].img);
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free_config(&cub->config);
	free_array(cub->textures);
	free_array(cub->map_copy);
	free(cub->mlx_s.mlx);
	exit(value);
}
