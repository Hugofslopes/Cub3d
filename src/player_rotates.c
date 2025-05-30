/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:00:47 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 19:01:23 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_cub *cub)
{
	cub->keys_.rl = 1;
	cub->player.angle -= ROTATION_SPEED ;
	if (cub->player.angle < 0)
		cub->player.angle += 360;
}

void	rotate_right(t_cub *cub)
{
	cub->keys_.rr = 1;
	cub->player.angle += ROTATION_SPEED ;
	if (cub->player.angle >= 360)
		cub->player.angle -= 360;
}
