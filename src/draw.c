/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:53:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/28 14:10:40 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WWIDTH && y >= 0 && y < WHEIGHT)
	{
		pxl = cub->img.addr + (y *  cub->img.line_len + x * \
		(cub->img.bytes_p_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}
