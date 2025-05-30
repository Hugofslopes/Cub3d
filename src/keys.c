/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:31:47 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 11:51:26 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_close(t_cub *cub)
{
	free_exit(cub);
	exit(0);
	return (0);
}

int can_zoom(t_cub *cub)
{
	int grid_x = (int)(cub->player.pos_x + 0.1);
	int grid_y = (int)(cub->player.pos_y + 0.1);

	if (grid_x < 0 || grid_x >= cub->game.map_with ||
	    grid_y < 0 || grid_y >= cub->game.map_height)
		return 0;

	if (cub->map[grid_y][grid_x] == '1')
		return 0; // You're standing in a wall

	return 1; // You're in a valid tile
}

void	i_speed(t_cub *cub)
{
	cub->keys_.b = 1;
	cub->player.speed += 0.1;
}

void	d_speed(t_cub *cub)
{
	cub->keys_.nb = 1;
	cub->player.speed -= 0.1;
}

void zoom_in(t_cub *cub)
{
	/* if (can_zoom(cub)) */
		if (cub->game.cellsize <= 5)
			++cub->game.cellsize;
}

void zoom_out(t_cub *cub)
{
	/* if (can_zoom(cub)) */
		if (cub->game.cellsize >= 3)
			--cub->game.cellsize;
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == 65307)
	{
		free_exit(cub);
		exit(0);
	}
	else if (key == 'w' || key == 'W')
		move_forward(cub);
	else if (key == 'a' || key == 'A')
		move_left(cub);
	else if (key == 's' || key == 'S')
		move_back(cub);
	else if (key == 'd' || key == 'D')
		move_right(cub);
	else if (key == 'r' || key == 'R')
		i_speed(cub);
	else if (key == 't' || key == 't')
		d_speed(cub);
	else if (key == 65361)
		rotate_left(cub);
	else if (key == 65363)
		rotate_right(cub);
	//printf("angle- %f \n", cub->player.angle), printf("X- %f \n", cub->player.pos_x), printf("Y- %f \n", cub->player.pos_y);
	else if (key == 65362)
		zoom_in(cub);
	else if (key == 65364)
		zoom_out(cub);
	printf("CELL-%d\n",cub->game.cellsize);
	return (0);
}
