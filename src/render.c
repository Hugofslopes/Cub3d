#include "../includes/cub3d.h"

unsigned int get_texture_color(t_cub *cub, int x, int y, int index)
{
    char	*pxl;

    if (x < 0 || x >= cub->texture[index].width || y < 0 || y >= cub->texture[index].height)
        return 0;
    pxl = cub->texture[index].addr + (y * cub->texture[index].line_len + x * (cub->texture[index].bytes_p_pixel / 8));
    return *(unsigned int *)pxl;
}

/*  void renderFrame(t_cub *cub)
{
    for (size_t x = 0; x < NUM_RAYS; x++)
    {
        double dist = cub->game.ray_values[x];
        if (dist <= 0)
            continue;
        int line_height = (int)(WHEIGHT / dist); 
        int draw_start = -line_height / 2 + WHEIGHT / 2;
        int draw_end = line_height / 2 + WHEIGHT / 2;
        if (draw_start < 0) draw_start = 0;
        if (draw_end >= WHEIGHT) draw_end = WHEIGHT - 1;
        WallDirection wall_side = cub->game.wall_directions[x];
        int texture_index = (int) wall_side;
        int texX = (int)(cub->game.hitPositions[x] * cub->texture[texture_index].width);
        if (texX < 0) texX = 0;
        if (texX >= cub->texture[texture_index].width) texX = cub->texture[texture_index].width -1;
        for (int y = draw_start; y <= draw_end; y++)
        {
            int d = y * 256 - WHEIGHT * 128 + line_height * 128;
            int texY = ((d * cub->texture[texture_index].height) / line_height) / 256;
            if (texY < 0) texY = 0;
            if (texY >= cub->texture[texture_index].height) texY = cub->texture[texture_index].height -1;
            unsigned int color = get_texture_color(cub, texX, texY, texture_index);
            put_pixel(cub, x, y, color);
        }
    }
}  */
void renderFrame(t_cub *cub)
{
    double projection_plane_dist = (WWIDTH / 2) / tan(deg_to_rad(FOV_ANGLE / 2));
    for (size_t x = 0; x < NUM_RAYS; x++)
    {
        double dist = cub->game.ray_values[x];
        if (dist <= 0)
            continue;
        int line_height = (int)(projection_plane_dist / dist);
        int draw_start = -line_height / 2 + WHEIGHT / 2;
        int draw_end = line_height / 2 + WHEIGHT / 2;
        if (draw_start < 0) draw_start = 0;
        if (draw_end >= WHEIGHT) draw_end = WHEIGHT - 1;
        WallDirection wall_side = cub->game.wall_directions[x];
        int texture_index = (int) wall_side;
        int texX = (int)(cub->game.hitPositions[x] * cub->texture[texture_index].width);
        if (texX < 0) texX = 0;
        if (texX >= cub->texture[texture_index].width) texX = cub->texture[texture_index].width - 1;
        for (int y = draw_start; y <= draw_end; y++)
        {
            int d = y * 256 - WHEIGHT * 128 + line_height * 128;
            int texY = ((d * cub->texture[texture_index].height) / line_height) / 256;
            if (texY < 0) texY = 0;
            if (texY >= cub->texture[texture_index].height) texY = cub->texture[texture_index].height - 1;
            unsigned int color = get_texture_color(cub, texX, texY, texture_index);
            put_pixel(cub, x, y, color);
        }
    }
}

