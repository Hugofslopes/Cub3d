/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:20:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 17:33:06 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	init_vars(t_end *end, t_cub *cub)
{
	end->dx[0] = 0;
	end->dx[1] = 1;
	end->dx[2] = -1;
	end->dx[3] = 0;
	end->dx[4] = 0;
	end->dy[0] = 0;
	end->dy[1] = 0;
	end->dy[2] = 0;
	end->dy[3] = 1;
	end->dy[4] = -1;
	end->player_tile_x = (int)(cub->player.pos_x / cub->game.cellsize);
	end->player_tile_y = (int)(cub->player.pos_y / cub->game.cellsize);
}

int	is_near_exit2(t_cub *cub, t_end *end)
{
	end->door_center_x = end->check_x * cub->game.cellsize + \
	cub->game.cellsize / 2.0f;
	end->door_center_y = end->check_y * cub->game.cellsize + \
	cub->game.cellsize / 2.0f;
	end->player_center_x = cub->player.pos_x;
	end->player_center_y = cub->player.pos_y;
	end->dx_pixel = end->player_center_x - end->door_center_x;
	end->dy_pixel = end->player_center_y - end->door_center_y;
	end->dist = sqrtf(end->dx_pixel * end->dx_pixel + end->dy_pixel * \
		end->dy_pixel);
	end->threshold = cub->game.cellsize * 0.75f;
	if (end->dist < end->threshold)
		return (1);
	return (0);
}

int	is_near_exit(t_cub *cub, size_t i)
{
	t_end	end;

	init_vars (&end, cub);
	while (i < 5)
	{
		end.check_x = end.player_tile_x + end.dx[i];
		end.check_y = end.player_tile_y + end.dy[i];
		if (end.check_x >= 0 && end.check_x < cub->map_width && \
			end.check_y >= 0 && end.check_y < cub->map_height)
		{
			if (cub->map[end.check_y][end.check_x] == 'D')
			{
				if (is_near_exit2(cub, &end))
					return (1);
			}
		}
		i++;
	}
	return (0);
}
