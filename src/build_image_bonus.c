/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:28:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 17:34:09 by hfilipe-         ###   ########.fr       */
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

void	end_game(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
	cub->end_screen.img = mlx_xpm_file_to_image(cub->mlx_s.mlx, "keys/end", \
		&cub->end_screen.width, &cub->end_screen.height);
	if (cub->end_screen.img == NULL)
	{
		ft_printf_fd(2, "%s %s \n%s ", CIMAGE, "keys/end", CHECKFILE);
		free_exit_textures(cub);
	}
	cub->end_screen.addr = mlx_get_data_addr(cub->end_screen.img, \
	&cub->end_screen.bytes_p_pixel, &cub->end_screen.line_len, \
	&cub->end_screen.endian);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
		cub->end_screen.img, 0, 0);
	mlx_loop(cub->mlx_s.mlx);
	exit(0);
}

void	first_render(t_cub *cub)
{
	set_keys(cub);
	cub->game.gamestarted = 1;
	ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
	set_floor_ceiling(cub);
	draw_c_f(cub, 0, 0);
	ray(cub, 0);
	render_frame(cub, 0, 0);
	check_put_arms(cub, 0, 0, 0);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
	cub->img.img, 0, 0);
}

int	build_next_frame(t_cub *cub)
{
	if (!cub->game.gamestarted)
		first_render(cub);
	else
	{
		if (is_near_exit(cub, 0))
			end_game(cub);
		mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
		cub->img.img = mlx_new_image(cub->mlx_s.mlx, WWIDTH, WHEIGHT);
		cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
		ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
		set_floor_ceiling(cub);
		draw_c_f(cub, 0, 0);
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
