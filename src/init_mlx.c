/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/28 16:59:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	first_render(t_cub *cub)
{
	cub->game.gamestarted = 1;
	cub->img.img = mlx_new_image(cub->mlx_s.mlx,
	WWIDTH, WHEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
	&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
	ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
	set_floor_ceiling(cub);
	draw_c_f(cub, 0, 0);
	ray(cub);
	renderFrame(cub); 
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
	cub->img.img, 0, 0);
}

int	build_next_frame(t_cub *cub)
{
	if (!cub->game.gamestarted)
		first_render(cub);
	else
	{
		mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
		cub->img.img = mlx_new_image(cub->mlx_s.mlx,
		WWIDTH, WHEIGHT);
		cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
		ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
		set_floor_ceiling(cub);
		draw_c_f(cub, 0, 0);
		ray(cub);
		renderFrame(cub); 
		mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
			cub->img.img, 0, 0);
	}
	return (0);
}

void	init_textures(t_cub *cub, size_t i){
	while (i < 4)
	{
		cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx_s.mlx, \
		cub->textures[i], &cub->texture[i].width, &cub->texture[i].height);
		cub->texture[i].addr = mlx_get_data_addr(cub->texture[i].img, \
		&cub->texture[i].bytes_p_pixel, &cub->texture[i].line_len, \
		&cub->texture[i].endian);
		i++;
	}
}

void	init_mlx(t_cub *cub)
{
	cub->mlx_s.mlx = mlx_init();
	cub->mlx_s.window = mlx_new_window(cub->mlx_s.mlx, WWIDTH, WHEIGHT, "Cub");
	cub->img.img = mlx_new_image(cub->mlx_s.mlx,
		WWIDTH, WHEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
}
