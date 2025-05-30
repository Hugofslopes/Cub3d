#include "../includes/cub3d.h"

unsigned int get_texture_color(t_cub *cub, int x, int y, int index)
{
    char	*pxl;

    if (x < 0 || x >= cub->texture[index].width || y < 0 || y >= cub->texture[index].height)
        return 0;
    pxl = cub->texture[index].addr + (y * cub->texture[index].line_len + x * (cub->texture[index].bytes_p_pixel / 8));
    return *(unsigned int *)pxl;
}


/* void renderFrame(t_cub *cub)
{
    double projection_plane_dist = (WWIDTH / 2.0) / tan(deg_to_rad(FOV_ANGLE / 2.0));

    for (int x = 0; x < NUM_RAYS; x++)
    {
        double dist = cub->game.ray_values[x];
        if (dist <= 0)
            continue;

        // Wall slice height
        int line_height = (int)(projection_plane_dist / dist);

        int draw_start = -line_height / 2 + WHEIGHT / 2;
        int draw_end = line_height / 2 + WHEIGHT / 2;

        if (draw_start < 0) draw_start = 0;
        if (draw_end >= WHEIGHT) draw_end = WHEIGHT - 1;

        WallDirection wall_side = cub->game.wall_directions[x];
        int texture_index = (int)wall_side;

        double hit_pos = cub->game.hitPositions[x]; // [0.0 to 1.0]
        int texX = (int)(hit_pos * cub->texture[texture_index].width);
        if (texX < 0) texX = 0;
        if (texX >= cub->texture[texture_index].width)
            texX = cub->texture[texture_index].width - 1;

        for (int y = draw_start; y <= draw_end; y++)
        {
            // Fixed-point scaling (if you're using fixed-point math)
            int d = y * FIXED_POINT - WHEIGHT * HALF_FIXED + line_height * HALF_FIXED;
            int texY = ((d * cub->texture[texture_index].height) / line_height) / FIXED_POINT;

            if (texY < 0) texY = 0;
            if (texY >= cub->texture[texture_index].height)
                texY = cub->texture[texture_index].height - 1;

            unsigned int color = get_texture_color(cub, texX, texY, texture_index);
            put_pixel(cub, x, y, color);
        }
    }
} */


// Helper: Darken color based on distance factor (0.0 to 1.0)
unsigned int darken_color(unsigned int color, double factor)
{
    if (factor < 0.2) factor = 0.2; // prevent too dark

    unsigned char a = (color >> 24) & 0xFF;
    unsigned char r = (color >> 16) & 0xFF;
    unsigned char g = (color >> 8) & 0xFF;
    unsigned char b = color & 0xFF;

    r = (unsigned char)(r * factor);
    g = (unsigned char)(g * factor);
    b = (unsigned char)(b * factor);

    return (a << 24) | (r << 16) | (g << 8) | b;
}


void renderFrame(t_cub *cub)
{
    double projection_plane_dist = (WWIDTH / 2.0) / tan(deg_to_rad(FOV_ANGLE / 2.0));

    for (int x = 0; x < NUM_RAYS; x++)
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
        int texture_index = (int)wall_side;

        double hit_pos = cub->game.hitPositions[x]; // [0.0 to 1.0]
        int texX = (int)(hit_pos * cub->texture[texture_index].width);
        if (texX < 0) texX = 0;
        if (texX >= cub->texture[texture_index].width)
            texX = cub->texture[texture_index].width - 1;

        for (int y = draw_start; y <= draw_end; y++)
        {
            int d = y * FIXED_POINT - WHEIGHT * HALF_FIXED + line_height * HALF_FIXED;
            int texY = ((d * cub->texture[texture_index].height) / line_height) / FIXED_POINT;

            if (texY < 0) texY = 0;
            if (texY >= cub->texture[texture_index].height)
                texY = cub->texture[texture_index].height - 1;

            unsigned int base_color = get_texture_color(cub, texX, texY, texture_index);

            // Adjust brightness: closer = brighter, further = darker
            double brightness = 1.0 / (1.0 + dist * 0.05); // tweak 0.05 for strength
            unsigned int color = darken_color(base_color, brightness);

            put_pixel(cub, x, y, color);
        }
    }
}



