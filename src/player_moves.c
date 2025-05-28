
#include "../includes/cub3d.h"

double round_increment(double value, double increment)
{
    return round(value / increment) * increment;
}


#define MOVE_INCREMENT 0.5

void move_forward(t_cub *cub)
{
    double dx = cos(cub->player.angle) * MOVE_SPEED;
    double dy = sin(cub->player.angle) * MOVE_SPEED;

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

// Similarly for move_left and move_right:
void move_left(t_cub *cub)
{
    double dx = sin(cub->player.angle) * MOVE_SPEED;
    double dy = cos(cub->player.angle) * MOVE_SPEED;

    dx = round_increment(dx, MOVE_INCREMENT);
    dy = round_increment(dy, MOVE_INCREMENT);

    double nx = cub->player.pos_x + dx;
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
    double dx = sin(cub->player.angle) * MOVE_SPEED;
    double dy = cos(cub->player.angle) * MOVE_SPEED;

    dx = round_increment(dx, MOVE_INCREMENT);
    dy = round_increment(dy, MOVE_INCREMENT);

    double nx = cub->player.pos_x - dx;
    double ny = cub->player.pos_y + dy;

    int mx = (int)(nx / CELLSIZE);
    int my = (int)(ny / CELLSIZE);

    if (!is_wall(cub, mx, my))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}
