#include "../includes/cub3d.h"

double  deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

int is_wall(t_cub *cub, int mapX, int mapY)
{
	
    if (mapX < 0 || mapX >= cub->game.map_with - 0.5 || mapY < 0 || mapY >= cub->game.map_height -  0.5) // Use map dimensions
        return 1;
    return (cub->map[mapY][mapX] == '1');
}

double cast_ray(t_cub *cub, double angle, WallDirection *wall_side, int ray_index)
{
    // Normalize angle to [0, 2*PI)
    angle = fmod(angle + 360.0, 360.0);
    cub->player.ray_angle = deg_to_rad(angle); // Ensure this is in radians

    double stepSize = 0.1;  // Smaller step size for better accuracy

    // Use pixel coordinates for ray start (make sure pos_x and pos_y are in pixels)
    cub->player.ray_x = cub->player.pos_x;
    cub->player.ray_y = cub->player.pos_y;

    int prev_mapx = (int)(cub->player.ray_x / CELLSIZE);
    int prev_mapy = (int)(cub->player.ray_y / CELLSIZE);

    while (1)
    {
        // Update ray position using the angle in radians
        cub->player.ray_x += cos(cub->player.ray_angle) * stepSize;
        cub->player.ray_y += sin(cub->player.ray_angle) * stepSize;

        int mapx = (int)(cub->player.ray_x / CELLSIZE);
        int mapy = (int)(cub->player.ray_y / CELLSIZE);

        int crossed_horizontal = (mapy != prev_mapy);
        int crossed_vertical = (mapx != prev_mapx);

        prev_mapx = mapx;
        prev_mapy = mapy;

        if (is_wall(cub, mapx, mapy))
        {
            double dx = cub->player.ray_x - cub->player.pos_x;
            double dy = cub->player.ray_y - cub->player.pos_y;
            double hit_dist = sqrt(dx * dx + dy * dy); // Use raw distance

            // No fish-eye correction, use hit_dist directly
            if (hit_dist < 0.001)
                hit_dist = 0.001; // Avoid division by zero later

            double hit_pos;
            if (crossed_vertical) {
                hit_pos = fmod(cub->player.ray_y, CELLSIZE) / CELLSIZE;
            } else {
                hit_pos = fmod(cub->player.ray_x, CELLSIZE) / CELLSIZE;
            }

            // Store hit position by ray index, not angle
            cub->game.hitPositions[ray_index] = hit_pos;

            // Determine wall side
            if (crossed_vertical && crossed_horizontal) {
                if (fabs(cos(cub->player.ray_angle)) > fabs(sin(cub->player.ray_angle))) {
                    *wall_side = (cos(cub->player.ray_angle) > 0) ? WEST : EAST;
                }
                else {
                    *wall_side = (sin(cub->player.ray_angle) > 0) ? SOUTH : NORTH;
                }
            }
            else if (crossed_vertical) {
                *wall_side = (cos(cub->player.ray_angle) > 0) ? WEST : EAST;
            }
            else if (crossed_horizontal) {
                *wall_side = (sin(cub->player.ray_angle) > 0) ? SOUTH : NORTH;
            }
            else {
                *wall_side = NORTH;
            }

            return hit_dist; // Return raw distance
        }

        // Out of bounds check
        if (cub->player.ray_x < 0 || cub->player.ray_x >= WWIDTH * CELLSIZE ||
            cub->player.ray_y < 0 || cub->player.ray_y >= WHEIGHT * CELLSIZE)
        {
            *wall_side = NORTH;
            return -1;
        }
    }
}

void ray(t_cub *cub)
{
    double start_angle = cub->player.angle - (FOV_ANGLE / 2);
    double angle_step = FOV_ANGLE / NUM_RAYS;

    for (size_t i = 0; i < NUM_RAYS; i++)
    {
        WallDirection wall_dir;
        double ray_angle = start_angle + i * angle_step;

        // Normalize ray_angle to [0, 360)
        if (ray_angle < 0)
            ray_angle += 360;
        else if (ray_angle >= 360)
            ray_angle -= 360;

        cub->game.ray_values[i] = cast_ray(cub, ray_angle, &wall_dir, i);

        if (cub->game.ray_values[i] > 0)
            cub->game.wall_directions[i] = wall_dir;
        else {
            cub->game.hitPositions[i] = 0;
            cub->game.wall_directions[i] = NORTH;
        }
    }
}
