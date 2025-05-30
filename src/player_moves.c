
#include "../includes/cub3d.h"

void print_cub(t_cub *cub, double mapX, double mapY)
{
    printf("X- %f\nY-%f\n", mapX, mapY);
	for (int i = 0; cub->map[i] != NULL; i++)
        printf("%s\n", cub->map[i]);
	printf("\n\n");	
}


int is_wall_move(t_cub *cub, double x, double y, int dirX, int dirY)
{
    double offset = 0.15;
    double checkX = x + (dirX * offset);
    double checkY = y + (dirY * offset);

    int checkMapX = (int)checkX;
    int checkMapY = (int)checkY;

    if (checkMapX < 0 || checkMapX >= cub->game.map_with ||
        checkMapY < 0 || checkMapY >= cub->game.map_height)
        return 1;

    if (cub->map[checkMapY][checkMapX] == '1')
        return 1;

    return 0;
}

void move_back(t_cub *cub)
{
    cub->keys_.s = 1;

    double angle_rad = deg_to_rad(cub->player.angle);
    double dx = cos(angle_rad) * cub->player.speed;
    double dy = sin(angle_rad) * cub->player.speed;

    double nx = cub->player.pos_x - dx;
    double ny = cub->player.pos_y - dy;

    // Direction signs
    int dirX = (dx < 0) ? 1 : (dx > 0) ? -1 : 0;
    int dirY = (dy < 0) ? 1 : (dy > 0) ? -1 : 0;

    print_cub(cub, nx / cub->game.cellsize, ny / cub->game.cellsize);
    if (!is_wall_move(cub, nx / cub->game.cellsize, ny / cub->game.cellsize, dirX, dirY))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_right(t_cub *cub)
{
    cub->keys_.d = 1;

    double angle_rad = deg_to_rad(cub->player.angle + 90);
    double dx = cos(angle_rad) * cub->player.speed;
    double dy = sin(angle_rad) * cub->player.speed;

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    int dirX = (dx > 0) ? 1 : (dx < 0) ? -1 : 0;
    int dirY = (dy > 0) ? 1 : (dy < 0) ? -1 : 0;

    print_cub(cub, nx / cub->game.cellsize, ny / cub->game.cellsize);
    if (!is_wall_move(cub, nx / cub->game.cellsize, ny / cub->game.cellsize, dirX, dirY))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_left(t_cub *cub)
{
    cub->keys_.a = 1;

    double angle_rad = deg_to_rad(cub->player.angle - 90);
    double dx = cos(angle_rad) * cub->player.speed;
    double dy = sin(angle_rad) * cub->player.speed;

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;


    int dirX = (dx > 0) ? 1 : (dx < 0) ? -1 : 0;
    int dirY = (dy > 0) ? 1 : (dy < 0) ? -1 : 0;

    print_cub(cub, nx / cub->game.cellsize, ny / cub->game.cellsize);
    if (!is_wall_move(cub, nx / cub->game.cellsize, ny / cub->game.cellsize, dirX, dirY))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}

void move_forward(t_cub *cub)
{
    cub->keys_.w = 1;

    double angle_rad = deg_to_rad(cub->player.angle);
    double dx = cos(angle_rad) * cub->player.speed;
    double dy = sin(angle_rad) * cub->player.speed;

    double nx = cub->player.pos_x + dx;
    double ny = cub->player.pos_y + dy;

    // Movement direction sign (-1, 0 or 1)
    int dirX = (dx > 0) ? 1 : (dx < 0) ? -1 : 0;
    int dirY = (dy > 0) ? 1 : (dy < 0) ? -1 : 0;

    if (!is_wall_move(cub, nx / cub->game.cellsize, ny / cub->game.cellsize, dirX, dirY))
    {
        cub->player.pos_x = nx;
        cub->player.pos_y = ny;
    }
}
