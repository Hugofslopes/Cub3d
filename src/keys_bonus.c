/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:28:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/31 11:29:03 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_close(t_cub *cub)
{
	free_exit(cub, 0);
	return (0);
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == 65307)
		free_exit(cub, 0);
	else if (key == 'w' || key == 'W')
		move_forward(cub, deg_to_rad(cub->player.angle));
	else if (key == 'a' || key == 'A')
		move_left(cub, deg_to_rad(cub->player.angle - 90));
	else if (key == 's' || key == 'S')
		move_back(cub, deg_to_rad(cub->player.angle));
	else if (key == 'd' || key == 'D')
		move_right(cub, deg_to_rad(cub->player.angle + 90));
	else if (key == 65361)
		rotate_left(cub);
	else if (key == 65363)
		rotate_right(cub);
	else if (key == 'r' || key == 'R')
		i_speed(cub);
	else if (key == 't' || key == 't')
		d_speed(cub);
	else if (key == 65362)
		zoom_in(cub);
	else if (key == 65364)
		zoom_out(cub);
	return (0);
}
