#include "../includes/cub3d.h"

char **test_Array(t_cub *cub)
{

    char **test;
    test = malloc(sizeof(char *) * 9);
    
    test[0] ="11111111";
	test[1] ="10000001";
	test[2] ="10000001";
	test[3] ="10000001";
	test[4] ="10000001";
	test[5] ="10000001";
	test[6] ="10000001";
	test[7] ="11111111";
    test[8] = NULL;

    cub->player.start_position = 'N';

    cub->textures = malloc(sizeof(char *) * 5);
    if (!cub->textures) {
        fprintf(stderr, "Memory allocation failed for textures array\n");
        exit(EXIT_FAILURE);
    }

    cub->textures[0] = ft_strdup("N");
    cub->textures[1] = ft_strdup("S");
    cub->textures[2] = ft_strdup("E");
    cub->textures[3] = ft_strdup("W");
    cub->textures[4] = NULL; 

    cub->ceiling.r = 20;
    cub->ceiling.g = 2;
    cub->ceiling.b = 10;
    cub->floor.r = 2;
    cub->floor.g = 20;
    cub->floor.b = 20;

	cub->player.pos_x = 3 * CELLSIZE + CELLSIZE / 2;
  	cub->player.pos_y = 5 * CELLSIZE + CELLSIZE / 2;
	cub->game.map_with = 8;
	cub->game.map_height = 8;

    return test;
}
