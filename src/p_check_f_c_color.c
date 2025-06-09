#include "../includes/cub3d.h"

int	handle_floor(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->f_set)
		return (ft_printf_fd(2, "%sDuplicate floor color\n", ERROR), 0);
	if (!parse_rgb(value, &cfg->floor_color))
		return (ft_printf_fd(2, "%sInvalid floor RGB value\n", ERROR), 0);
	cfg->floor_color_set = 1;
	flags->f_set = 1;
	return (1);
}

int	handle_ceiling(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->c_set)
		return (ft_printf_fd(2, "%sDuplicate ceiling color\n", ERROR), 0);
	if (!parse_rgb(value, &cfg->ceiling_color))
		return (ft_printf_fd(2, "%sInvalid ceiling RGB value\n", ERROR), 0);
	cfg->ceiling_color_set = 1;
	flags->c_set = 1;
	return (1);
}

int	parse_single_rgb(char **ptr, int *val)
{
	while (is_space_char(**ptr))
		(*ptr)++;
	if (!ft_isdigit(**ptr))
		return (0);
	*val = ft_atoi(*ptr);
	if (*val < 0 || *val > 255)
		return (0);
	while (ft_isdigit(**ptr))
		(*ptr)++;
	while (is_space_char(**ptr))
		(*ptr)++;
	return (1);
}

int	parse_rgb(char *raw, t_rgb *color)
{
	char	*ptr;
	int		vals[3];
	int		i;

	ptr = raw;
	i = 0;
	while (i < 3)
	{
		if (!parse_single_rgb(&ptr, &vals[i]))
			return (0);
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
