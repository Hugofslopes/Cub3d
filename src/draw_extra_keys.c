/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extra_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:33:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/19 10:02:08 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_i_key(t_cub *cub, size_t *i)
{
	if (cub->keys_.w == 1)
		*i = 0;
	else if (cub->keys_.s == 1)
		*i = 1;
	else if (cub->keys_.a == 1)
		*i = 2;
	else if (cub->keys_.d == 1)
		*i = 3;
	else
		*i = 4;
}

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

void	check_put_key(t_cub *cub, size_t i, int x, int y)
{
	int		dest_x;
	int		dest_y;
	char	*src_pixel;
	int		start_x;
	int		start_y;

	get_i_key(cub, &i);
	start_x = WWIDTH - cub->keys[i].width;
	start_y = WHEIGHT - cub->keys[i].height;
	while (y < cub->keys[i].height)
	{
		while (x < cub->keys[i].width)
		{
			src_pixel = cub->keys[i].addr + (y * cub->keys[i].line_len + x * \
				(cub->keys[i].bytes_p_pixel / 8));
			dest_x = start_x + x;
			dest_y = start_y + y;
			if ((*(unsigned int *)src_pixel & 0x00FFFFFF) != 0)
				put_pixel(cub, dest_x, dest_y, *(unsigned int *)src_pixel);
			x++;
		}
		y++;
		x = 0;
	}
}

void	get_arms(t_cub *cub, size_t *i)
{
	if (cub->keys_.arms >= 0 && cub->keys_.arms <= 4)
		*i = 9;
	else if (cub->keys_.arms >= 5 && cub->keys_.arms <= 9)
		*i = 10;
	else if (cub->keys_.arms >= 10 && cub->keys_.arms <= 14)
		*i = 11;
	else if (cub->keys_.arms >= 15 && cub->keys_.arms <= 19)
		*i = 12;
	else if (cub->keys_.arms >= 20 && cub->keys_.arms <= 24)
		*i = 13;
	else if (cub->keys_.arms >= 25 && cub->keys_.arms <= 29)
		*i = 12;
	else if (cub->keys_.arms >= 30 && cub->keys_.arms <= 34)
		*i = 11;
	else if (cub->keys_.arms >= 35 && cub->keys_.arms <= 39)
	{
		*i = 10;
		cub->keys_.arms = 0;
	}
	else
		*i = 9;
}

void	check_put_arms(t_cub *cub, size_t i, int x, int y)
{
	int		dest_x;
	int		dest_y;
	char	*src_pixel;
	int		start_x;
	int		start_y;

	get_arms(cub, &i);
	start_x = (WWIDTH / 2) - (cub->keys[i].width / 2);
	start_y = WHEIGHT - cub->keys[i].height;
	while (y < cub->keys[i].height)
	{
		while (x < cub->keys[i].width)
		{
			src_pixel = cub->keys[i].addr + (y * cub->keys[i].line_len + x * \
				(cub->keys[i].bytes_p_pixel / 8));
			dest_x = start_x + x;
			dest_y = start_y + y;
			if ((*(unsigned int *)src_pixel & 0x00FFFFFF) != 0)
				put_pixel(cub, dest_x, dest_y, *(unsigned int *)src_pixel);
			x++;
		}
		y++;
		x = 0;
	}
}
