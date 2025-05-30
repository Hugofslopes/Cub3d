/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:43:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 18:32:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_direction(int dx, int dy, int *dir_x, int *dir_y)
{
	if (dx > 0)
		*dir_x = 1;
	else if (dx < 0)
		*dir_x = -1;
	else
		*dir_x = 0;
	if (dy > 0)
		*dir_y = 1;
	else if (dy < 0)
		*dir_y = -1;
	else
		*dir_y = 0;
}

void	move_back(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->keys_.s = 1;
	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x - cub->moves.dx;
	cub->moves.ny = cub->player.pos_y - cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_wall_move(cub, dir_x, dir_y))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}

void	move_right(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->keys_.d = 1;
	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x + cub->moves.dx;
	cub->moves.ny = cub->player.pos_y + cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_wall_move(cub, dir_x, dir_y))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}

void	move_left(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->keys_.a = 1;
	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x + cub->moves.dx;
	cub->moves.ny = cub->player.pos_y + cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_wall_move(cub, dir_x, dir_y))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}

void	move_forward(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->keys_.w = 1;
	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x + cub->moves.dx;
	cub->moves.ny = cub->player.pos_y + cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_wall_move(cub, dir_x, dir_y))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}
