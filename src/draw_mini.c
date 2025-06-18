/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:56:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 20:55:09 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/* Draw square shwoing the player positon on the map 
w =6, h=6, draws 6x6 square
	*/
void	draw_player_posi(t_cub *cub, int w, int h, unsigned int color)
{
	int		i;
	int		j;
	char	*pxl;

	i = cub->mini.player_y - 3;
	j = cub->mini.player_x - 3;
	while (i < cub->mini.player_y - 3 + h)
	{
		while (j < cub->mini.player_x - 3 + w)
		{
			if (j >= 0 && j < WWIDTH && i >= 0 && i < WHEIGHT)
			{
				pxl = cub->img.addr + (i * cub->img.line_len + j * \
			(cub->img.bytes_p_pixel / 8));
				*(unsigned int *)pxl = color;
			}
			j++;
		}
		j = cub->mini.player_x - 3;
		i++;
	}
}

/*Draws the minimap base rectangle*/
void	draw_mini_rect(t_cub *cub, int w, int h, unsigned int color)
{
	int		i;
	int		j;
	char	*pxl;

	i = cub->mini.rect_y;
	j = cub->mini.rect_x;
	while (i < cub->mini.rect_y + h)
	{
		while (j < cub->mini.rect_x + w)
		{
			if (j >= 0 && j < WWIDTH && i >= 0 && i < WHEIGHT)
			{
				pxl = cub->img.addr + (i * cub->img.line_len + j * \
			(cub->img.bytes_p_pixel / 8));
				*(unsigned int *)pxl = color;
			}
			j++;
		}
		j = cub->mini.rect_x;
		i++;
	}
}

/*Draws a line pixel-by-pixel using Bresenham's algorithm
sx/xy are the steps (increments)
the err decides to move vertically or horizontally
loops stops when it reachs the endpoint
*/
void	draw_line(t_cub *cub, int x1, int y1, int dx)
{
	char	*pxl;

	set_line_values(cub, x1, y1);
	while (1)
	{
		if (cub->mini.player_x == x1 && cub->mini.player_y == y1)
			break ;
		pxl = cub->img.addr + (cub->mini.player_y * cub->img.line_len + \
			cub->mini.player_x * \
			(cub->img.bytes_p_pixel / 8));
		*(unsigned int *)pxl = 0xFFFF00FF;
		cub->mini.e2 = 2 * cub->mini.err;
		if (cub->mini.e2 >= cub->mini.dy)
		{
			cub->mini.err += cub->mini.dy;
			cub->mini.player_x += cub->mini.sx;
		}
		if (cub->mini.e2 <= dx)
		{
			cub->mini.err += dx;
			cub->mini.player_y += cub->mini.sy;
		}
	}
}

/*Converts player angle to rad for cos and sin
Calculates the endpoint coordinates for the line based on the player 
position and angle
Uses the err acumulator to check how far we are from the real position
*/
void	draw_player_line(t_cub *cub)
{
	double	angle_rad;
	int		line_x;
	int		line_y;
	int		dx;

	angle_rad = deg_to_rad(cub->player.angle);
	line_x = cub->mini.player_x + (int)(cos(angle_rad) * MINIMAP_SCALE * 2);
	line_y = cub->mini.player_y + (int)(sin(angle_rad) * MINIMAP_SCALE * 2);
	dx = abs(line_x - cub->mini.player_x);
	cub->mini.dy = -abs(line_y - cub->mini.player_y);
	cub->mini.err = dx + cub->mini.dy;
	draw_line(cub, line_x, line_y, dx);
}

void	draw_minimap(t_cub *cub, int y, int x, unsigned int color)
{
	draw_minimap_border(cub, 0x0000FFFF, MINIMAP_MARGIN - 1, \
		MINIMAP_MARGIN - 1);
	while (y < cub->map_height)
	{
		while (x < cub->map_width)
		{
			if (cub->map[y][x] == '1')
				color = 0x10FFFFFF;
			else
				color = 0x20000000;
			cub->mini.rect_x = MINIMAP_MARGIN + x * MINIMAP_SCALE;
			cub->mini.rect_y = MINIMAP_MARGIN + y * MINIMAP_SCALE;
			draw_mini_rect(cub, MINIMAP_SCALE, MINIMAP_SCALE, color);
			x++;
		}
		x = 0;
		y++;
	}
	cub->mini.player_x = MINIMAP_MARGIN + (int)(cub->player.pos_x / \
		cub->game.cellsize * MINIMAP_SCALE);
	cub->mini.player_y = MINIMAP_MARGIN + (int)(cub->player.pos_y / \
		cub->game.cellsize * MINIMAP_SCALE);
	draw_player_posi(cub, 6, 6, 0x000000FF);
	draw_player_line(cub);
}
