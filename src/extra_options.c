/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:17:01 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 12:19:12 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	can_zoom(t_cub *cub, int n)
{
	int	grid_x;
	int	grid_y;
	int	tmp_cellsize;

	tmp_cellsize = cub->game.cellsize;
	if (n)
		tmp_cellsize++;
	else 
		tmp_cellsize--;
	grid_x = (int)(cub->player.pos_x / tmp_cellsize);
	grid_y = (int)(cub->player.pos_y / tmp_cellsize);
	if (grid_x < 0 || grid_x >= cub->map_width || \
		grid_y < 0 || grid_y >= cub->map_height)
		return (0);
	if (cub->map[grid_y][grid_x] == '1' || cub->map[grid_y][grid_x] == 'X')
		return (0);
	return (1);
}

int	key_released(int key, t_cub *cub)
{
	if (key == 65505 || key == 65506)
	{
		cub->player.faster = 0;
		cub->player.speed /= 2.0;
	}
	return (0);
}

void	zoom_in(t_cub *cub)
{
	if (can_zoom(cub, 1))
	{
		if (cub->game.cellsize <= 5)
			++cub->game.cellsize;
	}
}

void	zoom_out(t_cub *cub)
{
	if (can_zoom(cub, -1))
	{
		if (cub->game.cellsize >= 2)
			--cub->game.cellsize;
	}
}
