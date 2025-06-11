/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:27:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/11 10:52:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Receives dir_x/y that form the direction vector
Calculates the new position
Cheks if it is inside of the map, an then if it is a wall
Uses offset to block the player from getting to close to the wall */
int	is_wall_move(t_cub *cub, int dir_x, int dir_y)
{
	double	offset;
	double	check_x;
	double	check_y;
	int		check_mapx;
	int		check_mapy;

	offset = 0.1;
	check_x = (cub->moves.nx / cub->game.cellsize) + (dir_x * offset);
	check_y = (cub->moves.ny / cub->game.cellsize) + (dir_y * offset);
	check_mapx = (int)floor(check_x);
	check_mapy = (int)floor(check_y);
	if (check_mapx < 0 || check_mapx >= cub->map_width || \
		check_mapy < 0 || check_mapy >= cub->map_height)
		return (1);
	if (cub->map[check_mapy][check_mapx] == '1')
		return (1);
	return (0);
}

/*When i already have the full coordinates*/
int	is_wall(t_cub *cub, int mapX, int mapY)
{
	if (mapX < 0 || mapX >= cub->map_width || \
		mapY < 0 || mapY >= cub->map_height)
		return (1);
	if (cub->map[mapY][mapX] == '1')
		return (1);
	else
		return (0);
}
