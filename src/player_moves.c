/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:43:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 19:20:05 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_direction(double dx, double dy, int *dir_x, int *dir_y)
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

/*Calculate how far the player would move in the X and Y directions,
based on their facing angle and speed;
Substract the distance from the position that it is
On moving forward we add the distance */
void	move_back(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x - cub->moves.dx;
	cub->moves.ny = cub->player.pos_y - cub->moves.dy;
	get_direction(-cub->moves.dx, -cub->moves.dy, &dir_x, &dir_y);
	if (!is_out_of_map(cub, cub->moves.nx, cub->moves.ny))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}

void	move_right(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x + cub->moves.dx;
	cub->moves.ny = cub->player.pos_y + cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_out_of_map(cub, cub->moves.nx, cub->moves.ny))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}

void	move_left(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x + cub->moves.dx;
	cub->moves.ny = cub->player.pos_y + cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_out_of_map(cub, cub->moves.nx, cub->moves.ny))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}

void	move_forward(t_cub *cub, double angle_rad)
{
	int		dir_x;
	int		dir_y;

	cub->moves.dx = cos(angle_rad) * cub->player.speed;
	cub->moves.dy = sin(angle_rad) * cub->player.speed;
	cub->moves.nx = cub->player.pos_x + cub->moves.dx;
	cub->moves.ny = cub->player.pos_y + cub->moves.dy;
	get_direction(cub->moves.dx, cub->moves.dy, &dir_x, &dir_y);
	if (!is_out_of_map(cub, cub->moves.nx, cub->moves.ny))
	{
		cub->player.pos_x = cub->moves.nx;
		cub->player.pos_y = cub->moves.ny;
	}
}
