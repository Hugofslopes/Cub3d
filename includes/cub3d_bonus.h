/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:31:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/01 12:30:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"
# define MINIMAP_SCALE 14
# define MINIMAP_MARGIN 10

//			EXTRA OPTIONS
void	i_speed(t_cub *cub);
void	d_speed(t_cub *cub);
void	zoom_in(t_cub *cub);
void	zoom_out(t_cub *cub);

//				MINI
void	draw_minimap(t_cub *cub, int y, int x, unsigned int color);

//				EXTRA IMAGE
void	check_put_key(t_cub *cub, size_t i, int x, int y);
void	check_put_rotation(t_cub *cub, size_t i, int x, int y);
void	draw_boot(t_cub *cub, int i, int x, int y);
void	init_keys(t_cub *cub, size_t i);
void	check_put_arms(t_cub *cub, size_t i, int x, int y);

#endif