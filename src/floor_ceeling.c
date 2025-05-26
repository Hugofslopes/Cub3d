/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceeling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:01 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/26 19:02:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_c_f(t_cub *cub, size_t x, size_t y)
{ 
	while (x <  WWIDTH )
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

int	getcolor(t_cub *cub, char c)
{
	int	color;

	if (c == 'c')
		color = (cub->ceiling.r << 16) | (cub->ceiling.g << 8) | cub->ceiling.b;
	if (c == 'f')
		color = (cub->floor.r << 16) | (cub->floor.g << 8) | cub->floor.b;
	return (color);
}

void	set_floor_ceiling(t_cub *cub)
{
	cub->game.floor = getcolor(cub, 'c');
	cub->game.ceiling = getcolor(cub, 'f');
}