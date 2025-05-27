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

int	is_space_char(char c)
{
	return (c == ' ' || (c >= 9 &&  c <= 13));
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (!is_space_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_scene_file(int *fd, t_cub *cub)
{
	char	*line;
	char	*buffer;
	int		map_started;

	map_started = 0;
	while ((line = get_next_line(*fd, &buffer)))
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
	free(buffer);
	return (0);
}

/*int	parse_color(char *line, int color)
{

}*/
