/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:31:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 21:15:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"
# define MINIMAP_SCALE 8
# define MINIMAP_MARGIN 10

//				MINI
void	draw_minimap(t_cub *cub, int y, int x, unsigned int color);
void	draw_minimap_border(t_cub *cub, unsigned int color, int border_x, \
	int border_y);
void	set_line_values(t_cub *cub, int x1, int y1);

//				EXTRA IMAGE
void	check_put_key(t_cub *cub, size_t i, int x, int y);
void	check_put_rotation(t_cub *cub, size_t i, int x, int y);
void	draw_boot(t_cub *cub, int i, int x, int y);
void	init_keys(t_cub *cub, size_t i);
void	check_put_arms(t_cub *cub, size_t i, int x, int y);
void	put_pixel(t_cub *cub, int x, int y, int color);

//              EXTRA CLOSE
void	free_exit_keys(t_cub *cub, size_t i, int flag);

//              MOUSE
int		mouse_move(int x, int y, void *param);
void	ft_player_rotm(t_cub *cub);

#endif