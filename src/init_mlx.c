/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/26 22:07:59 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char    **test_Array(t_cub *cub);

void	first_render(t_cub *cub)
{
	(void)cub;
}

void	draw_extra(t_cub *cub)
{
	size_t x = 0 , y = 0;
	while (x <  WWIDTH ){
		put_pixel(cub, x++, y++, 8000);
	}
	x =WWIDTH, y =0;
	while (x > 0 ){
		put_pixel(cub, x--, y++, 8000);
	}
}

int	build_next_frame(t_cub *cub)
{
	/* if (cub->game.gamestarted)
		first_render(cub);
	else
	{ */
		//mlx_destroy_image(cub->mlx_s.mlx, cub->img.img);
		cub->img.img = mlx_new_image(cub->mlx_s.mlx,
		WWIDTH, WHEIGHT);
		cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
		ft_memset(cub->img.addr, 0, WHEIGHT * cub->img.line_len);
		set_floor_ceiling(cub);
		draw_c_f(cub, 0, 0);
		draw_extra(cub);
	/* 	ft_cast_rays(cub);
		if (game->map->show_map)
			ft_display_minimap(game);
		ft_update_gates(game); */
		mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
			cub->img.img, 0, 0);
	//}
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

int	init_mlx(t_cub *cub)
{
	cub->mlx_s.mlx = mlx_init();
	cub->mlx_s.window = mlx_new_window(cub->mlx_s.mlx, WWIDTH, WHEIGHT, "Cub");
	test_Array(cub);
	build_next_frame(cub);
	
	/* 
	init_textures(cub, 0);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, cub->texture[0].img, 0, 0);
	mlx_destroy_image(cub->mlx_s.mlx,cub->texture[0].img);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, cub->texture[1].img, 0, 0);
	mlx_destroy_image(cub->mlx_s.mlx,cub->texture[1].img);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, cub->texture[2].img, 0, 0);
	mlx_destroy_image(cub->mlx_s.mlx,cub->texture[2].img);
	mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, cub->texture[3].img, 0, 0);
	mlx_destroy_image(cub->mlx_s.mlx,cub->texture[3].img); */
	mlx_key_hook(cub->mlx_s.window, key_pressed, cub);
	
	//mlx_loop_hook(cub->mlx_s.mlx, build_next_frame, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
	return (0);
}
