#include "../includes/cub3d.h"

void rotate_left(t_cub *cub)
{
    cub->keys_.rl =1;

    cub->player.angle -= ROTATION_SPEED ;
    if (cub->player.angle < 0)
        cub->player.angle += 360;
}

void rotate_right(t_cub *cub)
{
     cub->keys_.rr = 1;
    cub->player.angle += ROTATION_SPEED ;
    if (cub->player.angle >= 360)
        cub->player.angle -= 360;
}
