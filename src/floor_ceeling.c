/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceeling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:01 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 19:08:22 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_c_f(t_cub *cub, size_t x, size_t y, char *pxl)
{
	while (x < WWIDTH)
	{
		y = WHEIGHT;
		while (y > WHEIGHT / 2)
		{
			pxl = cub->img.addr + (y * cub->img.line_len + x * \
			(cub->img.bytes_p_pixel / 8));
			*(unsigned int *)pxl = cub->game.ceiling;
			y--;
		}
		x++;
	}
	x = 0;
	while (x < WWIDTH)
	{
		y = 0;
		while (y < WHEIGHT / 2)
		{
			pxl = cub->img.addr + (y * cub->img.line_len + x * \
			(cub->img.bytes_p_pixel / 8));
			*(unsigned int *)pxl = cub->game.floor;
			y++;
		}
		x++;
	}
}
