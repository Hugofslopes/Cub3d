/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:28:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 21:15:45 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	mouse_close(t_cub *cub)
{
	free_exit(cub, 0);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_cub	*cub;
	int		new_pos;
	int		delta;

	cub = (t_cub *)param;
	cub->mouse.mouse = 0;
	if (x == cub->mouse.mouse_pos)
		return (0);
	if (x > WWIDTH - 10 || x < 10)
	{
		mlx_mouse_move(cub->mlx_s.mlx, cub->mlx_s.window,
			WWIDTH >> 1, WHEIGHT >> 1);
		cub->mouse.mouse_pos = WWIDTH >> 1;
		return (0);
	}
	else
	{
		new_pos = x - (WWIDTH >> 1);
		delta = new_pos - cub->mouse.mouse_pos;
		if (delta > -2 && delta < 2)
			delta = 0;
		cub->mouse.mouse = delta;
		cub->mouse.mouse_pos = new_pos;
	}
	return ((void) y, 0);
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == 65505 || key == 65506)
	{
		cub->player.faster = 1;
		if (cub->player.faster)
			cub->player.speed *= 2.0;
	}
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
	if (key == 65505 || key == 65506)
	{
		cub->player.faster = 0;
		cub->player.speed /= 2.0;
	}
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
	if (cub->mouse.mouse != 0)
		ft_player_rotm(cub);
}
