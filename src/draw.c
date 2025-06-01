/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:53:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/01 12:38:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Pointer to start of the image pixel data, line len, move to the corect row,
x*.. moves to the correct collum
write the correct color to that point*/
void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WWIDTH && y >= 0 && y < WHEIGHT)
	{
		pxl = cub->img.addr + (y * cub->img.line_len + x * \
		(cub->img.bytes_p_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}
