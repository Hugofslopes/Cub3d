#include "../includes/cub3d.h"

void	cube_flood_fill(t_cub *cub, int **visited, int x, int y)
{
	if (x < 0 || y < 0 || y >= cub->map_height
		|| x >= (int)ft_strlen(cub->map_copy[y])
		|| cub->map_copy[y][x] == '1'
		|| cub->map_copy[y][x] == 'X'
		|| visited[y][x])
		return ;
	visited[y][x] = 1;
	cube_flood_fill(cub, visited, x + 1, y);
	cube_flood_fill(cub, visited, x - 1, y);
	cube_flood_fill(cub, visited, x, y + 1);
	cube_flood_fill(cub, visited, x, y - 1);
}

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	map_is_close_support(t_cub *cub, int y, int x)
{
	if (y == 0 || x == 0 || y >= cub->map_height - 1
		|| x >= (int)ft_strlen(cub->map_copy[y]) - 1
		|| cub->map_copy[y - 1][x] == 'X'
		|| cub->map_copy[y + 1][x] == 'X'
		|| cub->map_copy[y][x - 1] == 'X'
		|| cub->map_copy[y][x + 1] == 'X')
		return (ft_printf_fd(2, "%sMap not closed\n", ERROR), 1);
	return (0);
}

int	map_is_closed(t_cub *cub)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (cub->map_copy[y][x])
		{
			c = cub->map_copy[y][x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (map_is_close_support(cub, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	parse_map(t_cub *cub)
{
	int	**visited;

	if (normalize_map(cub))
		return (1);
	if (validate_map_chars(cub))
		return (1);
	if (cub->map_copy)
		free_array(cub->map_copy);
	dup_map(cub);
	if (!cub->map_copy)
		return (1);
	init_visited(cub, &visited);
	cube_flood_fill(cub, visited, cub->player_x, cub->player_y);
	if (check_unreachable_cells(cub, visited))
	{
		free_visited(visited, cub->map_height);
		return (1);
	}
	if (map_is_closed(cub))
	{
		free_visited(visited, cub->map_height);
		return (1);
	}
	free_visited(visited, cub->map_height);
	return (0);
}
