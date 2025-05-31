/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:25:34 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/31 10:22:42 by hfilipe-         ###   ########.fr       */
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

void	free_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		free(str);
	free(str);
}

void	free_exit(t_cub *cub, int value)
{
	size_t	i;

	i = 0;
	mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
	while (i < 4)
		mlx_destroy_image(cub->mlx_s.mlx, cub->texture[i++].img);
	i = 0;
	while (i < 10)
		mlx_destroy_image(cub->mlx_s.mlx, cub->keys[i++].img);
	mlx_destroy_window(cub->mlx_s.mlx, cub->mlx_s.window);
	mlx_destroy_display(cub->mlx_s.mlx);
	free(cub->mlx_s.mlx);
	free(cub->map);
	free(cub->textures);
	exit(value);
}
