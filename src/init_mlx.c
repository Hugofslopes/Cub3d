/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 11:57:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_keys(t_cub *cub)
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

void	first_render(t_cub *cub)
{
	set_keys(cub);
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

void	check_put_key(t_cub *cub)
{
	int x, y;
	int dest_x, dest_y;
	unsigned int color;
	char *src_pixel;
	size_t i;

	if (cub->keys_.w == 1)
		i =0;
	else if (cub->keys_.s == 1)
		i = 1;
	else if (cub->keys_.a == 1)
		i=2;
	else if (cub->keys_.d == 1)
		i=3;
	else
		i=4 ;

	int start_x = WWIDTH - cub->keys[i].width;  
	int start_y = WHEIGHT - cub->keys[i].height;

	for (y = 0; y < cub->keys[i].height; y++)
	{
		for (x = 0; x < cub->keys[i].width; x++)
		{
			src_pixel = cub->keys[i].addr + (y * cub->keys[i].line_len + x * (cub->keys[i].bytes_p_pixel / 8));
			color = *(unsigned int *)src_pixel;

			dest_x = start_x + x;
			dest_y = start_y + y;
			put_pixel(cub, dest_x, dest_y, color);
		}
	}
}


void	check_put_rotation(t_cub *cub)
{
	size_t i = 0;

	if (cub->keys_.rl == 1)
		i = 5; 
	else if (cub->keys_.rr == 1)
		i = 6;
	else
		i = 7; 


	// Draw it to the left of the movement key image
	int margin = 20;
	int start_x = WWIDTH - cub->keys[0].width - cub->keys[i].width - margin;
	int start_y = WHEIGHT -  cub->keys[i].height;

	// Reuse your draw logic (inline or helper)
	for (int y = 0; y <  cub->keys[i].height; y++)
	{
		for (int x = 0; x <  cub->keys[i].width; x++)
		{
			char *src_pixel =  cub->keys[i].addr + (y *  cub->keys[i].line_len + x * ( cub->keys[i].bytes_p_pixel / 8));
			unsigned int color = *(unsigned int *)src_pixel;

			put_pixel(cub, start_x + x, start_y + y, color);
		}
	}
}

void draw_boot(t_cub *cub)
{
		int i;
	if (!cub->keys_.b && !cub->keys_.nb)
		return;
	if (cub->keys_.b == 1)
		i = 8;
	else if (cub->keys_.nb == 1)
		i=  9;


	int start_x = 10; // 10 pixels from left edge
	int start_y = (WHEIGHT / 2) - (cub->keys[i].height / 2); // vertically centered

	for (int y = 0; y < cub->keys[i].height; y++)
	{
		for (int x = 0; x < cub->keys[i].width; x++)
		{
			char *src_pixel = cub->keys[i].addr + (y * cub->keys[i].line_len + x * (cub->keys[i].bytes_p_pixel / 8));
			unsigned int color = *(unsigned int *)src_pixel;

			// Skip transparency (you can adjust this based on your image format)
			if ((color & 0x00FFFFFF) != 0)
			{
				put_pixel(cub, start_x + x, start_y + y, color);
			}
		}
	}
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
		check_put_key(cub);
		check_put_rotation(cub);
		draw_minimap(cub);
		draw_boot(cub);
		mlx_put_image_to_window(cub->mlx_s.mlx, cub->mlx_s.window, \
			cub->img.img, 0, 0);
		set_keys(cub);
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
