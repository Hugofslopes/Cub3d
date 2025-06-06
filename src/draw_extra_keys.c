/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extra_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:33:08 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 12:04:09 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (cub->keys_.arms == 1)
		*i = 9;
	else
		*i = 10;
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
