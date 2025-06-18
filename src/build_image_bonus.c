/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:28:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 21:06:25 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_keys(t_cub *cub)
{
	cub->keys_.a = 0;
	cub->keys_.s = 0;
	cub->keys_.d = 0;
	cub->keys_.w = 0;
	cub->keys_.rl = 0;
	cub->keys_.rr = 0;
	cub->keys_.b = 0;
	cub->keys_.nb = 0;
}

void	ft_player_rotm(t_cub *cub)
{
	cub->player.angle += (int)(1.20 * cub->mouse.mouse);
}

void	first_render(t_cub *cub)
{
	char	*pxl;

	pxl = NULL;
	set_keys(cub);
	cub->game.gamestarted = 1;
	draw_c_f(cub, 0, WHEIGHT, pxl);
	ray(cub, 0);
	render_frame(cub, 0, 0);
	check_put_arms(cub, 0, 0, 0);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
	cub->img.img, 0, 0);
}

int	build_next_frame(t_cub *cub)
{
	char	*pxl;

	pxl = NULL;
	if (!cub->game.gamestarted)
		first_render(cub);
	else
	{
		mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
		cub->img.img = mlx_new_image(cub->mlx_s.mlx, WWIDTH, WHEIGHT);
		cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
		draw_c_f(cub, 0, WHEIGHT, pxl);
		change_player_pos(cub);
		ray(cub, 0);
		render_frame(cub, 0, 0);
		check_put_key(cub, 0, 0, 0);
		check_put_rotation(cub, 0, 0, 0);
		draw_minimap(cub, 0, 0, 0);
		draw_boot(cub, 0, 0, 0);
		check_put_arms(cub, 0, 0, 0);
		mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
			cub->img.img, 0, 0);
		set_keys(cub);
	}
	return (0);
}
