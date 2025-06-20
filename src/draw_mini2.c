/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:09:19 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 20:55:25 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_minimap_border(t_cub *cub, unsigned int color, int border_x, \
	int border_y)
{
	int	border_width;
	int	border_height;
	int	x;
	int	y;

	x = border_x;
	y = border_y;
	border_width = cub->map_width * MINIMAP_SCALE + 2;
	border_height = cub->map_height * MINIMAP_SCALE + 2;
	while (x < border_x + border_width)
	{
		put_pixel(cub, x, border_y, color);
		put_pixel(cub, x, border_y + border_height - 1, color);
		x++;
	}
	while (y < border_y + border_height)
	{
		put_pixel(cub, border_x, y, color);
		put_pixel(cub, border_x + border_width - 1, y, color);
		y++;
	}
}

void	set_line_values(t_cub *cub, int x1, int y1)
{
	if (cub->mini.player_x < x1)
		cub->mini.sx = 1;
	else
		cub->mini.sx = -1;
	if (cub->mini.player_y < y1)
		cub->mini.sy = 1;
	else
		cub->mini.sy = -1;
}
