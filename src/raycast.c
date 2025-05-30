/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:10:39 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 20:57:32 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycast_val(t_cub *cub, double angle_deg)
{
	angle_deg = normalize_angle(angle_deg);
	cub->rayc.angle = deg_to_rad(angle_deg);
	cub->rayc.mapx = (int)(cub->player.pos_x / cub->game.cellsize);
	cub->rayc.mapy = (int)(cub->player.pos_y / cub->game.cellsize);
	cub->rayc.raydirx = cos(cub->rayc.angle);
	cub->rayc.raydiry = sin(cub->rayc.angle);
	cub->rayc.deltadistx = fabs(1 / cub->rayc.raydirx);
	cub->rayc.deltadisty = fabs(1 / cub->rayc.raydiry);
	cub->rayc.hit = 0;
	cub->rayc.side = -1;
}

void	cast_ray2(t_cub *cub)
{
	if (cub->rayc.raydirx < 0)
	{
		cub->rayc.stepx = -1;
		cub->rayc.side_dstx = (cub->player.pos_x - cub->rayc.mapx * \
			cub->game.cellsize) / cub->game.cellsize * cub->rayc.deltadistx;
	}
	else
	{
		cub->rayc.stepx = 1;
		cub->rayc.side_dstx = ((cub->rayc.mapx + 1) * \
		cub->game.cellsize - cub->player.pos_x) / cub->game.cellsize * \
		cub->rayc.deltadistx;
	}
	if (cub->rayc.raydiry < 0)
	{
		cub->rayc.stepy = -1;
		cub->rayc.side_dsty = (cub->player.pos_y - cub->rayc.mapy * \
			cub->game.cellsize) / cub->game.cellsize * cub->rayc.deltadisty;
	}
	else
	{
		cub->rayc.stepy = 1;
		cub->rayc.side_dsty = ((cub->rayc.mapy + 1) * \
		cub->game.cellsize - cub->player.pos_y) / cub->game.cellsize * \
		cub->rayc.deltadisty;
	}
}

void	dda_loop(t_cub *cub)
{
	while (!cub->rayc.hit)
	{
		if (cub->rayc.side_dstx < cub->rayc.side_dsty)
		{
			cub->rayc.side_dstx += cub->rayc.deltadistx;
			cub->rayc.mapx += cub->rayc.stepx;
			cub->rayc.side = 0;
		}
		else
		{
			cub->rayc.side_dsty += cub->rayc.deltadisty;
			cub->rayc.mapy += cub->rayc.stepy;
			cub->rayc.side = 1;
		}
		if (is_wall(cub, cub->rayc.mapx, cub->rayc.mapy))
			cub->rayc.hit = 1;
	}
}

double	cast_ray(t_cub *cub, double angle_deg, t_wall_direction *wall_side, \
	int ray_index)
{
	init_raycast_val(cub, angle_deg);
	cast_ray2(cub);
	dda_loop(cub);
	if (cub->rayc.side == 0)
		cub->rayc.wall_dist = (cub->rayc.side_dstx - cub->rayc.deltadistx) * \
		cub->game.cellsize;
	else
		cub->rayc.wall_dist = (cub->rayc.side_dsty - cub->rayc.deltadisty) * \
		cub->game.cellsize;
	if (cub->rayc.side == 0)
		cub->rayc.wall_hit = fmod((cub->player.pos_y + cub->rayc.wall_dist * \
			cub->rayc.raydiry), cub->game.cellsize) / cub->game.cellsize;
	else
		cub->rayc.wall_hit = fmod((cub->player.pos_x + cub->rayc.wall_dist * \
			cub->rayc.raydirx), cub->game.cellsize) / cub->game.cellsize;
	cub->game.hit_positions[ray_index] = cub->rayc.wall_hit;
	set_wall_side(cub, wall_side);
	return (cub->rayc.wall_dist);
}

void	ray(t_cub *cub, int i)
{
	double				start_angle;
	double				angle_step;
	double				ray_angle;
	double				distance;
	t_wall_direction	wall_dir;

	start_angle = cub->player.angle - (FOV_ANGLE / 2.0);
	angle_step = FOV_ANGLE / NUM_RAYS;
	while (i < NUM_RAYS)
	{
		ray_angle = start_angle + i * angle_step;
		distance = cast_ray(cub, ray_angle, &wall_dir, i);
		cub->game.ray_values[i] = distance;
		cub->game.wall_directions[i] = wall_dir;
		i++;
	}
}
