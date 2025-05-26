#include "../includes/cub3d.h"

char    **test_Array(t_cub *cub)
{
	char    **test = malloc(sizeof(char *) * 6);
	for (size_t i = 0; i < 5; i++)
		test[i] = malloc(sizeof(char) * 9);

	for (size_t i = 0; i < 5; i++){
		for(size_t j = 0; j < 8; j++)
			test[i][j] = '1';
        test[i][8] = '\0';
    }
    test[6] = 0;
	test[3][5] = 'N';

	cub->textures = malloc(sizeof(char *) * 5);
	for (size_t i = 0; i < 4; i++)
		cub->textures[i] = malloc(sizeof(char) * 2);
	cub->textures[0][0] = 'N';
	cub->textures[1][0] = 'S';
	cub->textures[2][0] = 'E';
	cub->textures[3][0] = 'W';
	for (size_t i = 0; i < 4; i++)
		cub->textures[i][1] = '\0';
	cub->textures[5] = 0;

	cub->ceiling.r = 20;
	cub->ceiling.g = 2;
	cub->ceiling.b = 10;
	cub->floor.r = 2;
	cub->floor.g = 20;
	cub->floor.b = 20;
	
	return (test);
}

/* for (size_t i = 0; i < 5; i++){
    printf ("\n");
    for(size_t j = 0; j < 8; j++)
        printf ("%c ", test[i][j]);
} */