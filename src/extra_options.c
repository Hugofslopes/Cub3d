/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:17:01 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 17:32:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	can_zoom(t_cub *cub)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(cub->player.pos_x * 0.1);
	grid_y = (int)(cub->player.pos_y * 0.1);
	if (grid_x < 0 || grid_x >= cub->game.map_with || \
		grid_y < 0 || grid_y >= cub->game.map_height)
		return (0);
	if (cub->map[grid_y][grid_x] == '1')
		return (0);
	return (1);
}

void	i_speed(t_cub *cub)
{
	cub->keys_.b = 1;
	cub->player.speed += 0.5;
}

void	d_speed(t_cub *cub)
{
	cub->keys_.nb = 1;
	cub->player.speed -= 0.5;
}

void	zoom_in(t_cub *cub)
{
	if (can_zoom(cub))
		if (cub->game.cellsize <= 5)
			++cub->game.cellsize;
}

void	zoom_out(t_cub *cub)
{
	if (can_zoom(cub))
		if (cub->game.cellsize >= 3)
			--cub->game.cellsize;
}
