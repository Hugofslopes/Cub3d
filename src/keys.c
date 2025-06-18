/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:31:47 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 21:01:46 by hfilipe-         ###   ########.fr       */
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
		cub->keys_p.f_key = 1;
	else if (key == 'a' || key == 'A')
		cub->keys_p.l_key = 1;
	else if (key == 's' || key == 'S')
		cub->keys_p.b_key = 1;
	else if (key == 'd' || key == 'D')
		cub->keys_p.r_key = 1;
	else if (key == 65361)
		cub->keys_p.rtl_key = 1;
	else if (key == 65363)
		cub->keys_p.rtr_key = 1;
	return (0);
}

int	key_released(int key, t_cub *cub)
{
	if (key == 65307)
		free_exit(cub, 0);
	else if (key == 'w' || key == 'W')
		cub->keys_p.f_key = 0;
	else if (key == 'a' || key == 'A')
		cub->keys_p.l_key = 0;
	else if (key == 's' || key == 'S')
		cub->keys_p.b_key = 0;
	else if (key == 'd' || key == 'D')
		cub->keys_p.r_key = 0;
	else if (key == 65361)
		cub->keys_p.rtl_key = 0;
	else if (key == 65363)
		cub->keys_p.rtr_key = 0;
	return (0);
}

void	change_player_pos(t_cub *cub)
{
	if (cub->keys_p.f_key == 1)
		move_forward(cub, deg_to_rad(cub->player.angle));
	if (cub->keys_p.l_key == 1)
		move_left(cub, deg_to_rad(cub->player.angle - 90));
	if (cub->keys_p.b_key == 1)
		move_back(cub, deg_to_rad(cub->player.angle));
	if (cub->keys_p.r_key == 1)
		move_right(cub, deg_to_rad(cub->player.angle + 90));
	if (cub->keys_p.rtl_key == 1)
		rotate_left(cub);
	if (cub->keys_p.rtr_key == 1)
		rotate_right(cub);
}
