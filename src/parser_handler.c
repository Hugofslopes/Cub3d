#include "../includes/cub3d.h"

int	check_cub_extension(const char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub", 4))
		return (0);
	return (1);
}

int	open_scene_file(const char *filename, int *fd)
{
	if (!check_cub_extension(filename))
		return (ft_printf_fd(2, ERROF EXTENSION_ERR, 1));
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (ft_printf_fd(2, ERROF READ_FILE_ERR, 1));
	return (0);
}

int	parse_scene_file(int *fd, t_cub *cub)
{
	char	*line;
	int		map_started;

	map_started = 0;
	while ((line = get_next_line(*fd)))
	{
		if (!map_started && is_line_empty(line))
		{
			free(line);
			continue ;
		}
		if (!map_started && is_config_line(line))
		{
			if (!parse_config_line(line, &cub->config))
				return (free(line), 1);
		}
		else
		{
			map_started = 1;
			if (!append_map_line(cub, line))
				return (free(line), 1);
		}
		free(line);
	}
	return (0);
}

/*int	parse_color(char *line, int color)
{

}*/
