/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:48:27 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 21:01:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 360.0);
	if (angle < 0)
		angle += 360.0;
	return (angle);
}

void	set_wall_side(t_cub *cub, t_wall_direction *wall_side)
{
	if (cub->rayc.side == 0)
	{
		if (cub->rayc.raydirx > 0)
			*wall_side = EAST;
		else
			*wall_side = WEST;
	}
	else
	{
		if (cub->rayc.raydiry > 0)
			*wall_side = SOUTH;
		else
			*wall_side = NORTH;
	}
}
