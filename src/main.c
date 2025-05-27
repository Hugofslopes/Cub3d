#include "../includes/cub3d.h"

char	**test_Array(void);

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(cub)); // added this to start values from 0 or NULL
				     // or make a function (void init_cub(t_cub *cub) and call it from main)
	if (handle_input(ac, av, &cub))
		return (1);
	if (init_mlx(&cub))
		return(1);
	test_Array();
//	free_config(&cub.config);
	return (0);
}
/* 
-- first argument a scene description file with the .cub
-- Valid chars 1, 0, N, S ,E, W
-- Map must be close by walls(flood fill) (we can fill empty with *)
-- Remove empty lines on infos!!
-- The order of the inputs its not mandatory (receive, analizem and order)
-- elements must start with the type identifyer: NO, SO, WE, EA, F, C
-- NO path to nort texture (check if is valid and redeable)
-- SO path to south texture (check if is valid and redeable)
-- WE path to west texture (check if is valid and redeable)
-- EA path to east texture (check if is valid and redeable)
-- F flor olors in rgb (must be > 0 < 255)
-- Floor and ceeling must be diferent
-- C cealing colors
-- Errors Error\n , message error

NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
10010000000000000000000011111111
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
*/
