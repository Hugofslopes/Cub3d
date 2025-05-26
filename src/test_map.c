#include "../includes/cub3d.h"

char    **test_Array(void)
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
	return (test);
}

/* for (size_t i = 0; i < 5; i++){
    printf ("\n");
    for(size_t j = 0; j < 8; j++)
        printf ("%c ", test[i][j]);
} */