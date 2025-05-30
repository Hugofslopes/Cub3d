#include "../includes/cub3d.h"

double deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

double normalize_angle(double angle)
{
	angle = fmod(angle, 360.0);
	if (angle < 0)
		angle += 360.0;
	return angle;
}

int is_wall(t_cub *cub, int mapX, int mapY)
{
	if (mapX < 0 || mapX >= cub->game.map_with ||
		mapY < 0 || mapY >= cub->game.map_height)
		return 1;
	if (cub->map[mapY][mapX] == '1')
		return (1);
	else
		return (0);
	/* return (cub->map[mapY][mapX] == '1'); */
}

  double cast_ray(t_cub *cub, double angle_deg, WallDirection *wall_side, int ray_index)
{
	angle_deg = normalize_angle(angle_deg);
	double angle = deg_to_rad(angle_deg);

	// Map position
	int mapX = (int)(cub->player.pos_x / cub->game.cellsize);
	int mapY = (int)(cub->player.pos_y / cub->game.cellsize);

	// Direction vector
	double rayDirX = cos(angle);
	double rayDirY = sin(angle);

	// Length to next gridline (delta distance)
	double deltaDistX = fabs(1 / rayDirX);
	double deltaDistY = fabs(1 / rayDirY);

	int stepX, stepY;
	double sideDistX, sideDistY;

	// Calculate step and initial sideDist
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (cub->player.pos_x - mapX * cub->game.cellsize) / cub->game.cellsize * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = ((mapX + 1) * cub->game.cellsize - cub->player.pos_x) / cub->game.cellsize * deltaDistX;
	}

	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (cub->player.pos_y - mapY * cub->game.cellsize) / cub->game.cellsize * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = ((mapY + 1) * cub->game.cellsize - cub->player.pos_y) / cub->game.cellsize * deltaDistY;
	}

	// DDA loop
	int hit = 0;
	int side = -1; // 0 for X-side, 1 for Y-side

	while (!hit)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}

		if (is_wall(cub, mapX, mapY))
			hit = 1;
	}

	// Calculate distance to the wall
	double wall_dist;
	if (side == 0)
		wall_dist = (sideDistX - deltaDistX) * cub->game.cellsize;
	else
		wall_dist = (sideDistY - deltaDistY) * cub->game.cellsize;

	// Save wall hit position (for texture offset)
	double wall_hit;
	if (side == 0)
		wall_hit = fmod((cub->player.pos_y + wall_dist * rayDirY), cub->game.cellsize) / cub->game.cellsize;
	else
		wall_hit = fmod((cub->player.pos_x + wall_dist * rayDirX), cub->game.cellsize) / cub->game.cellsize;

	cub->game.hitPositions[ray_index] = wall_hit;

	// Determine wall direction
	if (side == 0)
		*wall_side = (rayDirX > 0) ?  EAST : WEST ;
	else
		*wall_side = (rayDirY > 0) ? SOUTH : NORTH;

	return wall_dist;
} 



void ray(t_cub *cub)
{
	double start_angle = cub->player.angle - (FOV_ANGLE / 2.0);
	double angle_step = FOV_ANGLE / NUM_RAYS;

	for (int i = 0; i < NUM_RAYS; i++)
	{
		double ray_angle = start_angle + i * angle_step;
		WallDirection wall_dir;

		double distance = cast_ray(cub, ray_angle, &wall_dir, i);

		cub->game.ray_values[i] = distance;
		cub->game.wall_directions[i] = wall_dir;
	}
}
