/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceeling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:01 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 12:57:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_c_f(t_cub *cub, size_t x, size_t y)
{
	while (x < WWIDTH)
	{
		y = 0;
		while (y < WHEIGHT / 2)
			put_pixel(cub, x, y++, cub->game.ceiling);
		x++;
	}
	x = 0;
	y = WHEIGHT;
	while (x < WWIDTH)
	{
		y = WHEIGHT;
		while (y > WHEIGHT / 2)
			put_pixel(cub, x, y--, cub->game.floor);
		x++;
	}
}

/* Each color has 8 bits so shift each color plus 8 bitsS*/
int	getcolor(t_cub *cub, char c)
{
	int	color;

	if (c == 'c')
		color = (cub->config.ceiling_color.r << 16) | \
		(cub->config.ceiling_color.g << 8) | cub->config.ceiling_color.b;
	if (c == 'f')
		color = (cub->config.floor_color.r << 16) | \
		(cub->config.floor_color.g << 8) | cub->config.floor_color.b;
	return (color);
}

void	set_floor_ceiling(t_cub *cub)
{
	cub->game.floor = getcolor(cub, 'c');
	cub->game.ceiling = getcolor(cub, 'f');
}
