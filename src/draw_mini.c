
#include "../includes/cub3d.h"

#define MINIMAP_SCALE 12     // Increased from 8 to 12 for a ~50px larger minimap
#define MINIMAP_MARGIN 10

void draw_filled_rect(t_cub *cub, int x, int y, int w, int h, unsigned int color)
{
    for (int i = y; i < y + h; i++)
    {
        for (int j = x; j < x + w; j++)
        {
            put_pixel(cub, j, i, color);
        }
    }
}

void draw_line(t_cub *cub, int x0, int y0, int x1, int y1, unsigned int color)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (1)
    {
        put_pixel(cub, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_minimap(t_cub *cub)
{
    // Draw the minimap grid (walls/floor)
    for (int y = 0; y < cub->game.map_height; y++)
    {
        for (int x = 0; x < cub->game.map_with; x++)
        {
            unsigned int color = (cub->map[y][x] == '1') ? 0xFFFFFFFF : 0x00000000;
            int rect_x = MINIMAP_MARGIN + x * MINIMAP_SCALE;
            int rect_y = MINIMAP_MARGIN + y * MINIMAP_SCALE;
            draw_filled_rect(cub, rect_x, rect_y, MINIMAP_SCALE, MINIMAP_SCALE, color);
        }
    }

    // Draw player position
    int player_x = MINIMAP_MARGIN + (int)(cub->player.pos_x / cub->game.cellsize * MINIMAP_SCALE);
    int player_y = MINIMAP_MARGIN + (int)(cub->player.pos_y / cub->game.cellsize * MINIMAP_SCALE);

    // Black border for visibility
    draw_filled_rect(cub, player_x - 3, player_y - 3, 6, 6, 0x000000FF);

    // Yellow player dot
    draw_filled_rect(cub, player_x - 2, player_y - 2, 4, 4, 0xFFFF00FF);  // Yellow

    // Draw facing direction line
    double angle_rad = deg_to_rad(cub->player.angle);
    int line_x = player_x + (int)(cos(angle_rad) * MINIMAP_SCALE * 2);
    int line_y = player_y + (int)(sin(angle_rad) * MINIMAP_SCALE * 2);
    draw_line(cub, player_x, player_y, line_x, line_y, 0xFFFF00FF);  // Yellow
}
