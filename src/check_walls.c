/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:27:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/01 11:13:48 by hfilipe-         ###   ########.fr       */
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

	offset = 0.25;
	check_x = (cub->moves.nx / cub->game.cellsize) + (dir_x * offset);
	check_y = (cub->moves.ny / cub->game.cellsize) + (dir_y * offset);
	check_mapx = (int)check_x;
	check_mapy = (int)check_y;
	if (check_mapx < 0 || check_mapx >= cub->game.map_with || \
		check_mapy < 0 || check_mapy >= cub->game.map_height)
		return (1);
	if (cub->map[check_mapy][check_mapx] == '1')
		return (1);
	return (0);
}

/*When i already have the full coordinates*/
int	is_wall(t_cub *cub, int mapX, int mapY)
{
	if (mapX < 0 || mapX >= cub->game.map_with || \
		mapY < 0 || mapY >= cub->game.map_height)
		return (1);
	if (cub->map[mapY][mapX] == '1')
		return (1);
	else
		return (0);
}

/* Receives x/y that form the direction vector
Calculates the new position
Cheks if it is inside of the map, an then if it is a wall
Uses offset to block the player from getting to close to the wall */
int	is_out_of_map(t_cub *cub, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / cub->game.cellsize);
	map_y = (int)(y / cub->game.cellsize);
	if (map_x < 0 || map_x >= cub->game.map_with || \
		map_y < 0 || map_y >= cub->game.map_height)
		return (1);
	if (cub->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
