#include "../includes/cub3d.h"

//Function helper to print portions of the map
void	print_map_part(t_cub *cub, int start, int end)
{
	int	i;

	if (!cub->map || start < 0 || end >= cub->map_height || start > end)
	{
		ft_printf_fd(2, "%sInvalid map range: [%d, %d]\n", ERROR, start, end);
		return ;
	}
	i = start;
	while (i <= end)
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
}

void	print_map_copy_part(t_cub *cub, int start, int end)
{
	int	i;

	if (!cub->map_copy || start < 0 || end >= cub->map_height || start > end)
	{
		ft_printf_fd(2, "%dInvalid map range: [%d, %d]\n", ERROR, start, end);
		return ;
	}
	i = start;
	while (i <= end)
	{
		printf("%s\n", cub->map_copy[i]);
		i++;
	}
}
