/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:44:10 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 20:25:01 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_texture_color(t_cub *cub, int x, int y, int index)
{
	char	*pxl;

	if (x < 0 || x >= cub->texture[index].width || y < 0 || \
		y >= cub->texture[index].height)
		return (0);
	pxl = cub->texture[index].addr + (y * cub->texture[index].line_len + x * \
		(cub->texture[index].bytes_p_pixel / 8));
	return (*(unsigned int *)pxl);
}

unsigned int	darken_color(unsigned int color, double factor)
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (factor < 0.2)
		factor = 0.2;
	a = (color >> 24) & 0xFF;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (unsigned char)(r * factor);
	g = (unsigned char)(g * factor);
	b = (unsigned char)(b * factor);
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

void	render_frame2(t_cub *cub, int y, int x)
{
	int	d;

	while (y <= cub->rend.draw_end)
	{
		d = y * FIXED_POINT - WHEIGHT * HALF_FIXED \
		+ cub->rend.line_height * HALF_FIXED;
		cub->rend.texy = ((d * \
			cub->texture[cub->rend.texture_index].height) / \
		cub->rend.line_height) / FIXED_POINT;
		if (cub->rend.texy < 0)
			cub->rend.texy = 0;
		if (cub->rend.texy >= cub->texture[cub->rend.texture_index].height)
			cub->rend.texy = cub->texture[cub->rend.texture_index].height - 1;
		cub->rend.base_color = get_texture_color(cub, cub->rend.texx, \
			cub->rend.texy, cub->rend.texture_index);
		cub->rend.brightness = 1.0 / (1.0 + cub->rend.dist * 0.05);
		put_pixel(cub, x, y, darken_color(cub->rend.base_color, \
			cub->rend.brightness));
		y++;
	}
}

void	render_frame(t_cub *cub, int x, double hit_pos)
{
	cub->rend.prj_pln_dt = (WWIDTH / 2.0) / tan(deg_to_rad(FOV_ANGLE / 2.0));
	while (x < NUM_RAYS)
	{
		cub->rend.dist = cub->game.ray_values[x];
		if (cub->rend.dist <= 0)
			continue ;
		cub->rend.line_height = (int)(cub->rend.prj_pln_dt / cub->rend.dist);
		cub->rend.draw_start = -cub->rend.line_height / 2 + WHEIGHT / 2;
		cub->rend.draw_end = cub->rend.line_height / 2 + WHEIGHT / 2;
		if (cub->rend.draw_start < 0)
			cub->rend.draw_start = 0;
		if (cub->rend.draw_end >= WHEIGHT)
			cub->rend.draw_end = WHEIGHT - 1;
		cub->rend.wall_side = cub->game.wall_directions[x];
		cub->rend.texture_index = (int)cub->rend.wall_side;
		hit_pos = cub->game.hit_positions[x];
		cub->rend.texx = (int)(hit_pos * \
			cub->texture[cub->rend.texture_index].width);
		if (cub->rend.texx < 0)
			cub->rend.texx = 0;
		if (cub->rend.texx >= cub->texture[cub->rend.texture_index].width)
			cub->rend.texx = cub->texture[cub->rend.texture_index].width - 1;
		render_frame2(cub, cub->rend.draw_start, x);
		x++;
	}
}
