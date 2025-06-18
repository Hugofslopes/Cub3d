/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extra_b_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:48:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 19:39:01 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_i_rotation(t_cub *cub, size_t *i)
{
	if (cub->keys_.rl == 1)
		*i = 5;
	else if (cub->keys_.rr == 1)
		*i = 6;
	else
		*i = 7;
}

/* Puts the side keys on the display:
Defines the place on the image;
Goes trough each pixel of the image and claculates the memory adress 
for each pixel;
Cast to unsigned int to get the color;
then puts it to the image*/
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
			if ((color & 0x00FFFFFF) != 0)
				put_pixel(cub, start_x + x, start_y + y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

int	get_i_check_boot(t_cub *cub, int *i)
{
	if (cub->player.faster)
	{
		*i = 8;
		return (0);
	}
	return (1);
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
