#include "../includes/cub3d.h"

int	get_max_width(char **map, int height)
{
	int	i;
	int	len;
	int	max_width;

	i = 0;
	max_width = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

int	fill_normalized_row(char *src, char *dst, int width)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(src);
	while (j < width)
	{
		if (j < len)
		{
			if (src[j] == ' ')
				dst[j] = 'X';
			else
				dst[j] = src[j];
		}
		else
			dst[j] = 'X';
		j++;
	}
	dst[width] = '\0';
	return (0);
}

void	free_partial_map(char **map, int until)
{
	while (--until >= 0)
		free(map[until]);
	free(map);
}

int	normalize_map(t_cub *cub)
{
	int		i;
	int		width;
	char	**normalized;

	width = get_max_width(cub->map, cub->map_height);
	normalized = malloc(sizeof(char *) * (cub->map_height + 1));
	if (!normalized)
		return (ft_printf_fd(2, "%sNormalize malloc\n", ERROR), 1);
	i = -1;
	while (++i < cub->map_height)
	{
		normalized[i] = malloc(width + 1);
		if (!normalized[i])
		{
			free_partial_map(normalized, i);
			return (ft_printf_fd(2, "%sNormalize malloc\n", ERROR), 1);
		}
		fill_normalized_row(cub->map[i], normalized[i], width);
	}
	normalized[cub->map_height] = NULL;
	free_array(cub->map);
	cub->map = normalized;
	cub->map_width = width;
	return (0);
}
