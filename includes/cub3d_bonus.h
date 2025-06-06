/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:31:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 17:21:35 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"
# define MINIMAP_SCALE 8
# define MINIMAP_MARGIN 10


typedef struct s_end
{
	int 	dx[5];
	int 	dy[5];
	int 	player_tile_x;
	int 	player_tile_y;
	int		check_x;
	int		check_y;
	float	door_center_x;
	float	door_center_y;
	float	player_center_x;
	float	player_center_y;
	float	dx_pixel;
	float	dy_pixel;
	float	dist;
	float	threshold;

}	t_end;

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

//				END
int	is_near_exit(t_cub *cub, size_t i);
#endif
