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

// function to check if it is space.
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
	printf("Entered is_config_line function\n");
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		printf("NEW_ENTER\n");
		return (1);
	}
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

static int	check_texture(const char *path, const char *name)
{
	if (!path)
		return (ft_printf_fd(2, "Error: %s texture missing\n", name), 1);
	if (access(path, F_OK) == -1)
		return (ft_printf_fd(2, "Error: NO texture file found at %s - %s", name, path), 1);
	return (0);
}

int	validate_config(t_config *cfg)
{
	if (check_texture(cfg->no_path, "NO "))
	{
		printf("Entered \n");
		return (1);
	}
	if (check_texture(cfg->so_path, "SO "))
		return (1);
	if (check_texture(cfg->we_path, "WE "))
		return (1);
	if (check_texture(cfg->ea_path, "EA "))
		return (1);
	if (!cfg->floor_color_set)
		return (ft_printf_fd(2, "Error: floor color not set\n"), 1);
	if (!cfg->ceiling_color_set)
		return (ft_printf_fd(2, "Error: Ceiling color not set\n"), 1);
	return (0);
}

int set_texture_path(char **dst, char *raw)
{
	char	*trimmed;

	if (!raw)
		return (0);
	trimmed = ft_strtrim(raw, " \t\n");
	if (!trimmed)
		return (0);
	free(*dst);
	*dst = ft_strdup(trimmed);
	free(trimmed);
	if (!*dst)
		return (0);
	return (1);
}

int	set_color(char **dst, char *color_start)
{
	while (*color_start == ' ' || *color_start == '\t')
		color_start++;
	if (*dst)
		return (0);
	*dst = ft_strdup(color_start);
	return (*dst != NULL);
}

static int	handle_no(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->no_set)
		return (ft_printf_fd(2, "Error: Duplicate NO texture\n"), 0);
	flags->no_set = 1;
	return (set_texture_path(&cfg->no_path, value));
}

static int	handle_so(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->so_set)
		return (ft_printf_fd(2, "Error: Duplicate SO texture\n"), 0);
	flags->so_set = 1;
	return (set_texture_path(&cfg->so_path, value));
}

static int	handle_we(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->we_set)
		return (ft_printf_fd(2, "Error: Duplicate WE texture\n"), 0);
	flags->we_set = 1;
	return (set_texture_path(&cfg->we_path, value));
}

static int	handle_ea(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->ea_set)
		return (ft_printf_fd(2, "Error: Duplicate EA texture\n"), 0);
	flags->ea_set = 1;
	return (set_texture_path(&cfg->ea_path, value));
}

static int	handle_floor(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->f_set)
		return (ft_printf_fd(2, "Error: Duplicate F texture\n"), 0);
	flags->f_set = 1;
	return (set_texture_path(&cfg->floor_color_set, value));
}

static int	handle_ceiling(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->c_set)
		return (ft_printf_fd(2, "Error: Duplicate F texture\n"), 0);
	flags->c_set = 1;
	return (set_texture_path(&cfg->ceiling_color_set, value));
}

int	parse_config_line(char *line, t_config *cfg, t_config_flags *flags)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		return handle_no(cfg, flags, line + 3);
	if (!ft_strncmp(line, "SO ", 3))
		return handle_so(cfg, flags, line + 3);
	if (!ft_strncmp(line, "WE ", 3))
		return handle_we(cfg, flags, line + 3);
	if (!ft_strncmp(line, "EA ", 3))
		return handle_ea(cfg, flags, line + 3);
	if (!ft_strncmp(line, "F ", 2))
		return handle_floor(cfg, flags, line + 2);
	if (!ft_strncmp(line, "C ", 2))
		return handle_ceiling(cfg, flags, line + 2);

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
	line = get_next_line(*fd, &buffer);
	printf("Entered parse_scene_file\n");
	while (line)
	{
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
			if (!parse_config_line(line, &cub->config, &cub->flags))
			{
				printf("Second Free\n");
				free(line);
				free(buffer);
				return (1);
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
		line = get_next_line(*fd, &buffer);
	}
	printf("Gets past while parse_scene_file\n");
	free(buffer);
	if (validate_config(&cub->config))
		return (1);
	return (0);
}

/*int	parse_color(char *line, int color)
{

}*/
