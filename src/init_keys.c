/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:56:20 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 20:27:51 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_keys(t_cub *cub, size_t i)
{
	char	*key[10];

	key[0] = "keys/fr";
	key[1] = "keys/bc";
	key[2] = "keys/lf";
	key[3] = "keys/rt";
	key[4] = "keys/bs";
	key[5] = "keys/rl";
	key[6] = "keys/rr";
	key[7] = "keys/lr";
	key[8] = "keys/bo";
	key[9] = "keys/nb";
	while (i < 10)
	{
		cub->keys[i].img = mlx_xpm_file_to_image(cub->mlx_s.mlx, \
		key[i], &cub->keys[i].width, &cub->keys[i].height);
		cub->keys[i].addr = mlx_get_data_addr(cub->keys[i].img, \
		&cub->keys[i].bytes_p_pixel, &cub->keys[i].line_len, \
		&cub->keys[i].endian);
		i++;
	}
}
