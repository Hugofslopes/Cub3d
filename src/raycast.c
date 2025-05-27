#include "../includes/cub3d.h"

double  deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

int is_wall(t_cub *cub, int mapX, int mapY)
{
	if (mapX < 0 || mapX >= WWIDTH || mapY < 0 || mapY >= WHEIGHT)
		return 1;
	return (cub->map[mapY][mapX] == '1');
}

double cast_ray(t_cub *cub, double angle)
{
	cub->player.ray_angle = deg_to_rad(angle);
	double stepSize = 1.0;
	cub->player.ray_x = cub->player.pos_x;
	while (1) 
	{
		cub->player.ray_x += cos(cub->player.ray_angle) * stepSize;
		cub->player.ray_y += sin(cub->player.ray_angle) * stepSize;
		cub->game.mapx = (int)(cub->player.pos_x / CELLSIZE);
		cub->game.mapy = (int)(cub->player.pos_y / CELLSIZE);
		if (is_wall(cub, cub->game.mapx, cub->game.mapy)) 
		{
			double dx = cub->player.ray_x - cub->player.pos_x ;
			double dy = cub->player.ray_y - cub->player.pos_y;
			return (sqrt(dx * dx + dy * dy));
		}
		if (cub->player.ray_x < 0 || cub->player.ray_x >= WWIDTH * CELLSIZE || \
			cub->player.ray_y < 0 || cub->player.ray_y >= WHEIGHT * CELLSIZE) 
			return -1;
	}
} 


void ray(t_cub *cub, size_t i, int angle) 
{
    while (angle <= 155)
    {
        
        cub->game.ray_values[i] = cast_ray(cub, (double)angle);
        if (cub->game.ray_values[i] > 0)
			cub->game.hitPositions[i] = cub->game.ray_values[i]/ (CELLSIZE * cub->texture[0].width); 
		else
			cub->game.hitPositions[i] = 0;
        //printf("Angle %3d°: Distance = %.2f units, Hit Position = %.2f\n", angle, distance, hitPositions[i]);
        i++;
        angle += 2;
    }
}