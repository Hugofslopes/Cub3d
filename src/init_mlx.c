/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:56 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/13 17:13:50 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_cub *cub)
{
	cub->mlx_s.mlx = mlx_init();
	cub->mlx_s.window = mlx_new_window(cub->mlx_s.mlx, WWIDTH, WHEIGHT, "Cub");
	cub->img.img = mlx_new_image(cub->mlx_s.mlx, WWIDTH, WHEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bytes_p_pixel, &cub->img.line_len, &cub->img.endian);
}
