#include "../includes/cub3d.h"

void	free_2d_partial(char **arr, int until)
{
	while (--until >= 0)
		free(arr[until]);
	free(arr);
}

//Function to allocate memory for each new line, and clean the old one.
char	**ft_realloc_2d(char **old, int new_size)
{
	char	**new_arr;
	int		i;

	new_arr = malloc(sizeof(char *) * (new_size + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (old && old[i] && i < new_size)
	{
		new_arr[i] = ft_strdup(old[i]);
		if (!new_arr[i])
			return (free_2d_partial(new_arr, i), NULL);
		i++;
	}
	new_arr[i] = NULL;
	if (old)
	{
		i = 0;
		while (old[i])
			free(old[i++]);
		free(old);
	}
	return (new_arr);
}

//Function to add new lines to the map
int	append_map_line(t_cub *cub, char *line)
{
	char	*trimmed;
	char	**tmp;

	trimmed = ft_strtrim(line, "\t\n");
	if (!trimmed)
		return (0);
	tmp = ft_realloc_2d(cub->map, cub->map_height + 1);
	if (!tmp)
		return (free(trimmed), 0);
	tmp[cub->map_height] = trimmed;
	tmp[cub->map_height + 1] = NULL;
	cub->map = tmp;
	cub->map_height++;
	return (1);
}

//Function to check if all configs are OK
int	all_config_flags_set(t_config_flags *flags, t_config *config)
{
	if (flags->no_set && flags->so_set && flags->we_set && flags->ea_set
		&& flags->f_set && flags->c_set)
	{
		if (validate_config(config))
			return (0);
		return (1);
	}
	return (0);
}
