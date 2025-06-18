/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:44:10 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 19:08:31 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Calculates the offset (d)
Converts the screen y-position to fixed-point format, to allow fractional math.
WHEIGHT * HALF_FIXED
This centers the screen vertically.
+ line_height * HALF_FIXED
Adds half the projected wall height to adjust for where the wall should appear.

Scales the d value to match the texture height.
Divides back by FIXED_POINT to convert it back to an integer index in 
texture space.

Check if it is inside of texture size

The distance from the player to the wall being drawn.
0.05: A scaling factor to control how fast brightness fades with distance.

*/
void	render_frame2(t_cub *cub, int y, int x, t_render rend)
{
	if (rend.texx >= cub->texture[rend.texture_index].width)
		rend.texx = cub->texture[rend.texture_index].width - 1;
	while (y <= rend.draw_end)
	{
		rend.d = y * FIXED_POINT - WHEIGHT * HALF_FIXED \
		+ rend.line_height * HALF_FIXED;
		rend.texy = ((rend.d * \
		cub->texture[rend.texture_index].height) / \
		rend.line_height) / FIXED_POINT;
		if (rend.texy < 0)
			rend.texy = 0;
		if (rend.texy >= cub->texture[rend.texture_index].height)
			rend.texy = cub->texture[rend.texture_index].height - 1;
		rend.base_color = \
		*(unsigned int *)(cub->texture[rend.texture_index].addr + \
		(rend.texy * cub->texture[rend.texture_index].line_len + rend.texx * \
		(cub->texture[rend.texture_index].bytes_p_pixel / 8)));
		if (x >= 0 && x < WWIDTH && y >= 0 && y < WHEIGHT)
		{
			rend.pxl = cub->img.addr + (y * cub->img.line_len + x * \
		(cub->img.bytes_p_pixel / 8));
			*(unsigned int *)rend.pxl = rend.base_color;
		}
		y++;
	}
}

/*Draws vertical slice of a wall texture;
Calculate how tall the wall should appear on screen.
Get where to draw the top part and htem botton
Check if it is betwen the bounds 
Determine which side of the wall was hit
Calculate which column of the texture (texx) to sample for this 
vertical wall slice.
hit_pos is a value between 0.0 and 1.0 (where the ray hit on the wall surface)
Multiply it by texture width to get the X coordinate in the texture
*/
void	render_frame(t_cub *cub, int x, double hit_pos)
{
	t_render	rend;

	rend.prj_pln_dt = (WWIDTH / 2.0) / tan(deg_to_rad(FOV_ANGLE / 2.0));
	while (x < NUM_RAYS)
	{
		rend.dist = cub->game.ray_values[x];
		if (rend.dist <= 0)
			continue ;
		rend.line_height = (int)(rend.prj_pln_dt / rend.dist);
		rend.draw_start = -rend.line_height / 2 + WHEIGHT / 2;
		rend.draw_end = rend.line_height / 2 + WHEIGHT / 2;
		if (rend.draw_start < 0)
			rend.draw_start = 0;
		if (rend.draw_end >= WHEIGHT)
			rend.draw_end = WHEIGHT - 1;
		rend.wall_side = cub->game.wall_directions[x];
		rend.texture_index = (int)rend.wall_side;
		hit_pos = cub->game.hit_positions[x];
		rend.texx = (int)(hit_pos * \
		cub->texture[rend.texture_index].width);
		if (rend.texx < 0)
			rend.texx = 0;
		render_frame2(cub, rend.draw_start, x, rend);
		x++;
	}
}
