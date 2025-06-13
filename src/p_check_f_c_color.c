/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_f_c_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:41:04 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/13 11:15:36 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_atoi(const char *str)
{
	int		sign;
	int		result;
	char	**nstr;
	char	*n_str;
	char	*n_str2;
	
	nstr = ft_split(str, ',');
	n_str2 = ft_strtrim(*nstr, " ");
	n_str = ft_strtrim(n_str2, "\t");
	if (ft_strlen(n_str) > 4)
		return (free(n_str), free(n_str2), free_array(nstr), -1);
	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str && *str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (free(n_str), free(n_str2), free_array(nstr),result * sign);
}


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
	*val = cub_atoi(*ptr);
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
