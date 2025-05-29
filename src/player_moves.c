
/* 
#define MOVE_INCREMENT 0.5  // Optional, you can remove round_increment for smooth movement

// Helper: rounds value to nearest increment (optional)
double round_increment(double value, double increment)
{
    return round(value / increment) * increment;
}

void move_forward(t_cub *cub)
{
    double dx = cos(cub->player.angle) * MOVE_SPEED;
    double dy = sin(cub->player.angle) * MOVE_SPEED;

    // Optional rounding (comment out if you want smooth movement)
    dx = round_increment(dx, MOVE_INCREMENT);
    dy = round_increment(dy, MOVE_INCREMENT);

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_back(t_cub *cub)
{
    double dx = cos(cub->player.angle) * MOVE_SPEED;
    double dy = sin(cub->player.angle) * MOVE_SPEED;

    dx = round_increment(dx, MOVE_INCREMENT);
    dy = round_increment(dy, MOVE_INCREMENT);

    double nx = cub->player.pos_x - dx;
    double ny = cub->player.pos_y - dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_right(t_cub *cub)
{
    // Right strafe is +90 degrees from facing angle
    double dx = sin(cub->player.angle) * MOVE_SPEED;
    double dy = -cos(cub->player.angle) * MOVE_SPEED;

    dx = round_increment(dx, MOVE_INCREMENT);
    dy = round_increment(dy, MOVE_INCREMENT);

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_left(t_cub *cub)
{
    // Left strafe is -90 degrees from facing angle
    double dx = sin(cub->player.angle) * MOVE_SPEED;
    double dy = -cos(cub->player.angle) * MOVE_SPEED;

    dx = round_increment(dx, MOVE_INCREMENT);
    dy = round_increment(dy, MOVE_INCREMENT);

    double nx = cub->player.pos_x - dx;
    double ny = cub->player.pos_y - dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}
 */

#include "../includes/cub3d.h"

void move_forward(t_cub *cub)
{
    double angle_rad = deg_to_rad(cub->player.angle);
    double dx = cos(angle_rad) * MOVE_SPEED;
    double dy = sin(angle_rad) * MOVE_SPEED;

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_back(t_cub *cub)
{
    double angle_rad = deg_to_rad(cub->player.angle);
    double dx = cos(angle_rad) * MOVE_SPEED;
    double dy = sin(angle_rad) * MOVE_SPEED;

    double nx = cub->player.pos_x - dx;
    double ny = cub->player.pos_y - dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_right(t_cub *cub)
{
    // Strafe right: angle + 90 degrees
    double angle_rad = deg_to_rad(cub->player.angle + 90);
    double dx = cos(angle_rad) * MOVE_SPEED;
    double dy = sin(angle_rad) * MOVE_SPEED;

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_left(t_cub *cub)
{
    // Strafe left: angle - 90 degrees
    double angle_rad = deg_to_rad(cub->player.angle - 90);
    double dx = cos(angle_rad) * MOVE_SPEED;
    double dy = sin(angle_rad) * MOVE_SPEED;

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

// Rotate left by ROTATE_SPEED degrees
void rotate_left(t_cub *cub)
{
    cub->player.angle -= ROTATION_SPEED ;
    if (cub->player.angle < 0)
        cub->player.angle += 360;
}

// Rotate right by ROTATION_SPEED  degrees
void rotate_right(t_cub *cub)
{
    cub->player.angle += ROTATION_SPEED ;
    if (cub->player.angle >= 360)
        cub->player.angle -= 360;
}
