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
	if (!check_cub_extension(filename))
		return (ft_printf_fd(2, "%s %s", ERROR, EXTENSION_ERR));
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (ft_printf_fd(2, "%s%s", ERROR, READ_FILE_ERR), 1);
	return (0);
}

// function to check if it is space.
int	is_space_char(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	parse_rgb(char *raw, t_rgb *color)
{
	char	*ptr;
	int		vals[3];
	int		i;

	ptr = raw;
	i = 0;
	while (i < 3)
	{
		while (is_space_char(*ptr))
			ptr++;
		if (!ft_isdigit(*ptr))
			return (0);
		vals[i] = ft_atoi(ptr);
		if (vals[i] < 0 || vals[i] > 255)
			return (0);
		while (ft_isdigit(*ptr))
			ptr++;
		while (is_space_char(*ptr))
			ptr++;
		if (i < 2 && *ptr++ != ',')
			return (0);
		i++;
	}
	while (is_space_char(*ptr))
		ptr++;
	if (*ptr != '\0')
		return (0);
	color->r = vals[0];
	color->g = vals[1];
	color->b = vals[2];
	return (1);
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

static int	check_texture(const char *path, const char *name)
{
	if (!path)
		return (ft_printf_fd(2, "%s%s %s", ERROR, name, TEXTURE), 1);
	if (access(path, F_OK) == -1)
		return (ft_printf_fd(2, "%s%s texture file not found\n", ERROR, name), 1);
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
		return (ft_printf_fd(2, "%sfloor color not set\n", ERROR), 1);
	if (!cfg->ceiling_color_set)
		return (ft_printf_fd(2, "%sCeiling color not set\n", ERROR), 1);
	return (0);
}

int	set_texture_path(char **dst, char *raw)
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
		return (ft_printf_fd(2, "Error: Duplicate floor color\n"), 0);
	if (!parse_rgb(value, &cfg->floor_color))
		return (ft_printf_fd(2, "Error: Invalid floor RGB value\n"), 0);
	cfg->floor_color_set = 1;
	flags->f_set = 1;
	return (1);
}

static int	handle_ceiling(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->c_set)
		return (ft_printf_fd(2, "Error: Duplicate ceiling color\n"), 0);
	if (!parse_rgb(value, &cfg->ceiling_color))
		return (ft_printf_fd(2, "Error: Invalid ceiling RGB value\n"), 0);
	cfg->ceiling_color_set = 1;
	flags->c_set = 1;
	return (1);
}

int	parse_config_line(char *line, t_config *cfg, t_config_flags *flags)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (flags->parsed_no)
			return (ft_printf_fd(2, "Error: duplicate 'NO' entry\n"), 0);
		if (flags->parse_step != 0)
			return (ft_printf_fd(2, "Error: 'NO' must come first in config\n"), 0);
		flags->parsed_no = 1;
		flags->parse_step++;
		return (handle_no(cfg, flags, line + 3));
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (flags->parsed_so)
			return (ft_printf_fd(2, "Error: duplicate 'SO' entry\n"), 0);
		if (flags->parse_step != 1)
			return (ft_printf_fd(2, "Error: 'SO' must come second in config\n"), 0);
		flags->parsed_so = 1;
		flags->parse_step++;
		return (handle_so(cfg, flags, line + 3));
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (flags->parsed_we)
			return (ft_printf_fd(2, "Error: duplicate 'WE' entry\n"), 0);
		if (flags->parse_step != 2)
			return (ft_printf_fd(2, "Error: 'WE' must come third in config\n"), 0);
		flags->parsed_we = 1;
		flags->parse_step++;
		return (handle_we(cfg, flags, line + 3));
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (flags->parsed_ea)
			return (ft_printf_fd(2, "Error: duplicate 'EA' entry\n"), 0);
		if (flags->parse_step != 3)
			return (ft_printf_fd(2, "Error: 'EA' must come fourth in config\n"), 0);
		flags->parsed_ea = 1;
		flags->parse_step++;
		return (handle_ea(cfg, flags, line + 3));
	}
	if (!ft_strncmp(line, "F ", 2))
	{
		if (flags->parsed_f)
			return (ft_printf_fd(2, "Error: duplicate 'F' entry\n"), 0);
		if (flags->parse_step != 4)
			return (ft_printf_fd(2, "Error: 'F' must come fifth in config\n"), 0);
		flags->parsed_f = 1;
		flags->parse_step++;
		return (handle_floor(cfg, flags, line + 2));
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (flags->parsed_c)
			return (ft_printf_fd(2, "Error: duplicate 'C' entry\n"), 0);
		if (flags->parse_step != 5)
			return (ft_printf_fd(2, "Error: 'C' must come sixth in config\n"), 0);
		flags->parsed_c = 1;
		flags->parse_step++;
		return (handle_ceiling(cfg, flags, line + 2));
	}
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
		{
			while (--i >= 0)
				free(new_arr[i]);
			free(new_arr);
			return (NULL);
		}
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
	if (flags->no_set && flags->so_set && flags->we_set && flags->ea_set && flags->f_set && flags->c_set)
	{
		if (validate_config(config))
			return (0);
		return (1);
	}
	return (0);
}

//Function helper to print portions of the map
void	print_map_part(t_cub *cub, int start, int end)
{
	int	i;

	if (!cub->map || start < 0 || end >= cub->map_height || start > end)
	{
		ft_printf_fd(2, "Invalid map range: [%d, %d]\n", start, end);
		return ;
	}
	i = start;
	while (i <= end)
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
}

//Function to make map copy to regular form XxY and **map points to the new normalized map
int	normalize_map(t_cub *cub)
{
	int		i;
	int		j;
	int		len;
	int		max_width;
	char	**normalized;

	i = 0;
	max_width = 0;
	while (i < cub->map_height)
	{
		len = ft_strlen(cub->map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}

	normalized = malloc(sizeof(char *) * (cub->map_height + 1));
	if (!normalized)
		return (ft_printf_fd(2, "Error normalize malloc\n", 1));
	i = 0;
	while (i < cub->map_height)
	{
		len = ft_strlen(cub->map[i]);
		normalized[i] = malloc(max_width + 1);
		if (!normalized[i])
		{
			while (--i >= 0)
				free(normalized[i]);
			free(normalized);
			return (ft_printf_fd(2, "Error normalize malloc\n"), 1);
		}
		j = 0;
		while (j < max_width)
		{
			if (j < len)
			{
				if (cub->map[i][j] == ' ')
					normalized[i][j] = 'X';
				else
					normalized[i][j] = cub->map[i][j];
			}
			else
				normalized[i][j] = 'X';
			j++;
		}
		normalized[i][max_width] = '\0';
		i++;
	}
	normalized[cub->map_height] = NULL;
	free_map(cub->map);
	cub->map = normalized;
	cub->map_width = max_width;
	return (0);
}

int     validate_map_chars(t_cub *cub)
{
        int             i;
        int             j;
        int             count;
        char    c;  

        i = 0;
        count = 0;
        while (i < cub->map_height)
        {
                j = 0;
                while (j < cub->map_width)
                {
                        c = cub->map[i][j];
				if (!ft_strchr("10NSEWX", c)) 
                                return(ft_printf_fd(2, "ERROR: Not allowed character [%c] was found\n", c), 1); 
                        if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
                                count++;
                        if (count > 1)
                                return(ft_printf_fd(2, "ERROR: More than one player position was found!\n"), 1); 
                        j++;
                }
                i++;
        }
        if (count == 0)
                return(ft_printf_fd(2, "ERROR: No player position was found at the map!\n"), 1); 
        return (0);    
}

int	parse_map(t_cub *cub)
{
	if (normalize_map(cub))
		return (1);
	if (validate_map_chars(cub))
		return (1);
	return (0);
}

void	dup_map(t_cub *cub)
{
	int		i;
	char	c;
	
	i = 0;
	cub->map_copy = malloc(sizeof(char *) * (cub->map_height));
	if (!cub->map_copy)
		return ;
	while (i < cub->map_height)
	{
		cub->map_copy[i] = malloc(sizeof(char) * (cub->map_width + 1));
		if (!cub->map_copy[i])
		{
			while (--i >= 0)
				free(cub->map_copy[i]);
			free (cub->map_copy);
			cub->map_copy = NULL;
			return ;
		}
		ft_strlcpy(cub->map_copy[i], cub->map[i], cub->map_width + 1);
		i++;
	}
}

int	flood_fill(char **map, int i, int j)
{
	char	c;

	if (i < 0 || j < 0 || map[i] == NULL || j >= ft_strlen(map[i]))
		return (1);
	c = map[i][j];
	if (c == 'X')
		return (1);
	if (c == '1' || c == 'F')
		return (0);
	map[i][j] = 

}

//function to parce the scene file PS
int	parse_scene_file(int *fd, t_cub *cub)
{
	char	*line;
	char	*buffer;
	int		map_started;
	int		i;

	buffer = NULL;
	map_started = 0;
	line = get_next_line(*fd, &buffer);
	while (line)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!map_started && (line[i] == '\0' || line[i] == '\n'))
		{
			free(line);
			line = get_next_line(*fd, &buffer);
			continue ;
		}
		if (!map_started)
		{
			if (is_config_line(line))
			{
				if (!parse_config_line(line, &cub->config, &cub->flags))
				{
					free(line);
					free(buffer);
					return (1);
				}
			}
			else if (validate_config(&cub->config))
			{
				free(line);
				free(buffer);
				return (1);
			}
			else if (all_config_flags_set(&cub->flags, &cub->config))
				map_started = 1;
			else
			{
				free(line);
				free(buffer);
				buffer = NULL;
				return (1);
			}
		}
		if (map_started)
		{
			if (!append_map_line(cub, line))
			{
				free(line);
				free(buffer);
				return (1);
			}
		}
		free(line);
		line = NULL;
		line = get_next_line(*fd, &buffer);
	}
	free(buffer);
	if (!check_map_no_empty_lines(cub->map))
	{
		ft_printf_fd(2, "There is an empty line at the map\n");
		free_map(cub->map);
		cub->map = NULL;
		return (1);
	}
	printf("ORIGINAL MAP\n------------\n");
	print_map_part(cub, 0, cub->map_height - 1);
	if (parse_map(cub))
		return(free_map(cub->map),1);
	printf("\nNORMALIZED MAP\n--------------\n");
	print_map_part(cub, 0, cub->map_height - 1);
	return (0);
}
