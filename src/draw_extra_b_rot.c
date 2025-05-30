/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extra_b_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:48:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 19:38:38 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_i_rotation(t_cub *cub, size_t *i)
{
	if (cub->keys_.rl == 1)
		*i = 5;
	else if (cub->keys_.rr == 1)
		*i = 6;
	else
		*i = 7;
}

void	check_put_rotation(t_cub *cub, size_t i, int x, int y)
{
	int				margin;
	int				start_x;
	int				start_y;
	char			*src_pixel;
	unsigned int	color;

	get_i_rotation(cub, &i);
	margin = 20;
	start_x = WWIDTH - cub->keys[0].width - cub->keys[i].width - margin;
	start_y = WHEIGHT - cub->keys[i].height;
	while (y < cub->keys[i].height)
	{
		while (x < cub->keys[i].width)
		{
			src_pixel = cub->keys[i].addr + (y * cub->keys[i].line_len + x * \
				(cub->keys[i].bytes_p_pixel / 8));
			color = *(unsigned int *)src_pixel;
			put_pixel(cub, start_x + x, start_y + y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

int	get_i_check_boot(t_cub *cub, int *i)
{
	if (!cub->keys_.b && !cub->keys_.nb)
		return (1);
	if (cub->keys_.b == 1)
		*i = 8;
	else if (cub->keys_.nb == 1)
		*i = 9;
	return (0);
}

void	draw_boot(t_cub *cub, int i, int x, int y)
{
	int				start_x;
	int				start_y;
	char			*src_pixel;
	unsigned int	color;

	if (get_i_check_boot(cub, &i))
		return ;
	start_x = 10;
	start_y = (WHEIGHT / 2) - (cub->keys[i].height / 2);
	while (y < cub->keys[i].height)
	{
		while (x < cub->keys[i].width)
		{
			src_pixel = cub->keys[i].addr + (y * cub->keys[i].line_len + x * \
				(cub->keys[i].bytes_p_pixel / 8));
			color = *(unsigned int *)src_pixel;
			if ((color & 0x00FFFFFF) != 0)
				put_pixel(cub, start_x + x, start_y + y, color);
			x++;
		}
		y++;
		x = 0;
	}
}
