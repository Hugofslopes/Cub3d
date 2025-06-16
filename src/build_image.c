/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:47:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/16 13:44:01 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	first_render(t_cub *cub)
{
	cub->game.gamestarted = 1;
	ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
	set_floor_ceiling(cub);
	draw_c_f(cub, 0, 0);
	ray(cub, 0);
	render_frame(cub, 0, 0);
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
		cub->img.img = mlx_new_image(cub->mlx_s.mlx, WWIDTH, WHEIGHT);
		cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
		ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
		set_floor_ceiling(cub);
		change_player_pos(cub);
		draw_c_f(cub, 0, 0);
		ray(cub, 0);
		render_frame(cub, 0, 0);
		mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
			cub->img.img, 0, 0);
	}
	return (0);
}
