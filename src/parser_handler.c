#include "../includes/cub3d.h"

// function to check whether it is a file with .cub extension
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
// function to open .cub file
int	open_scene_file(const char *filename, int *fd)
{
	printf("Entered open_scene_file\n");
	if (!check_cub_extension(filename))
		return (ft_printf_fd(2, ERROF EXTENSION_ERR, 1));
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (ft_printf_fd(2, ERROF READ_FILE_ERR, 1));
	printf("Exit open_scene_file\n");
	return (0);
}

int	is_space_char(char c)
{
	return (c == ' ' || (c >= 9 &&  c <= 13));
}

// function to check if a line is empty
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
// function to check whether t_config variable are null
int	validate_config(t_config *cfg)
{
	if (!cfg->no_path)
		return (ft_printf_fd(2, "Error: NO texture missing\n"), 0);
	if (!cfg->so_path)
		return (0);
	if (!cfg->we_path)
		return (0);
	if (!cfg->ea_path)
		return (0);
	if (!cfg->floor_color_set)
		return (0);
	if (!cfg->ceiling_color_set)
		return (0);
	return (1);
}

int	set_texture_path(char **dst, char *path_start)
{
	while (*path_start == ' ' || *path_start == '\t')
        	path_start++;
	if (*dst)
		return (0);
	*dst = ft_strdup(path_start);
	//*dst = path_start;
	return (*dst != NULL);
}

int	set_color(char **dst, char *color_start)
{
	while (*color_start == ' ' || *color_start == '\t')
		color_start++;
	if (*dst)
		return (0);
	*dst = ft_strdup(color_start);
	//*dst = color_start;
	return (*dst != NULL);
}

// function to store the path or color in each field of t_config
int	parse_config_line(char *line, t_config *cfg)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		printf("NO HAS BEEN FOUND\n");
		return (set_texture_path(&cfg->no_path, line + 3));
	}
	if (!ft_strncmp(line, "SO ", 3))
		return (set_texture_path(&cfg->so_path, line + 3));
	if (!ft_strncmp(line, "WE ", 3))
		return (set_texture_path(&cfg->we_path, line + 3));
	if (!ft_strncmp(line, "EA ", 3))
		return (set_texture_path(&cfg->ea_path, line + 3));
	if (!ft_strncmp(line, "F ", 2))
		return (set_color(&cfg->floor_color_set, line + 2));
	if (!ft_strncmp(line, "C ", 2))
		return (set_color(&cfg->ceiling_color_set, line + 2));
	return (0);
}

int	append_map_line(t_cub *cub, char *line)
{
	(void)cub;
	(void)line;
	return (1);
}

// base function to parse the scene file
int	parse_scene_file(int *fd, t_cub *cub)
{
	char	*line;
	char	*buffer;
	int		map_started;

	buffer = NULL;
	map_started = 0;
	printf("Entered parse_scene_file\n");
	while ((line = get_next_line(*fd, &buffer)))
	{
		if (!line)
			break;
		if (is_line_empty(line))
		{
			free(line);
			break;
		}
		if (!map_started && is_line_empty(line))
		{
			printf("First free\n");
			free(line);
			continue ;
		}
		if (!map_started && is_config_line(line))
		{
			if (!parse_config_line(line, &cub->config))
			{
				if (buffer)
					free(buffer);
				printf("Second Free\n");
				//free_config(&cub->config);
				return (free(line), 1);
			}
		}
		else
		{
			map_started = 1;
			if (!append_map_line(cub, line))
			{
				if (buffer)
					free(buffer);
				printf("Third Free\n");
				return (free(line), 1);
			}
		}
		printf("Forth free\n");
		free(line);
	}
	printf("Gets past while parse_scene_file\n");
	free(buffer);
	if (!validate_config(&cub->config))
		return (ft_printf_fd(2, ERROF CONF_ENTR_ERR, 1));
	return (0);
}

/*int	parse_color(char *line, int color)
{

}*/
