#include "../includes/cub3d.h"

// function to check the expression at config file exists
int	is_config_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	check_texture(const char *path, const char *name)
{
	(void)name;
	if (!path)
		return (ft_printf_fd(2, "%sTexture missing\n", ERROR), 1);
	if (access(path, F_OK) == -1)
		return (ft_printf_fd(2, "%sTexture file not found\n", ERROR), 1);
	return (0);
}

int	validate_config(t_config *cfg)
{
	if (check_texture(cfg->no_path, "NO "))
		return (1);
	if (check_texture(cfg->so_path, "SO "))
		return (1);
	if (check_texture(cfg->we_path, "WE "))
		return (1);
	if (check_texture(cfg->ea_path, "EA "))
		return (1);
	if (!cfg->floor_color_set)
		return (ft_printf_fd(2, "%sFloor color not set\n", ERROR), 1);
	if (!cfg->ceiling_color_set)
		return (ft_printf_fd(2, "%sCeiling color not set\n", ERROR), 1);
	return (0);
}

int	check_map_no_empty_lines(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			j++;
		if (map[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
