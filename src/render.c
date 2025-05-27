
#include "../includes/cub3d.h"

unsigned int get_texture_color(t_cub *cub, int x, int y)
{
    char	*pxl;

    if (x < 0 || x >= cub->texture[0].width || y < 0 || y >= cub->texture[0].height)
        return 0;
    pxl = cub->texture[0].addr + (y * cub->texture[0].line_len + x * (cub->texture[0].bytes_p_pixel / 8));
    return *(unsigned int *)pxl;
}

void	renderFrame(t_cub *cub, size_t x, size_t y) 
{
	double			dist;
	int				draw_end;
	int				draw_start;
	int				line_height;
	unsigned int	color;
	int				texX;
	int				texY;
	int				d;

	while (x <= 54)
	{
		dist = cub->game.ray_values[x];
		line_height = (int)(WHEIGHT / dist);
		draw_start = -line_height / 2 + WHEIGHT / 2;
		if (draw_start < 0) 
			draw_start = 0;
		draw_end = line_height / 2 + WHEIGHT / 2;
		if (draw_end >= WHEIGHT) 
			draw_end = WHEIGHT - 1;
		texX = (int)(cub->game.hitPositions[x] * cub->texture[0].width);
		if (texX < 0) 
			texX = 0;
		if (texX >= cub->texture[0].width) 
			texX = cub->texture[0].width - 1;
		y = draw_start;
		while ((int)y < draw_end)
		{
			d = y * 256 - WHEIGHT * 128 + line_height * 128;
			texY = ((d * cub->texture[0].height) / line_height) / 256;
			if (texY < 0) 
				texY = 0;
			if (texY >= cub->texture[0].height) 
				texY = cub->texture[0].height - 1;
			color = get_texture_color(cub, texX, texY);
			put_pixel(cub, x, y, color);
			y++;
		}
		x++;
	}
}
