/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handle_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:42:08 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/11 10:14:13 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	handle_north_south(char *line, t_config *cfg, t_config_flags *f)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (f->parsed_no)
			return (ft_printf_fd(2, "%sDuplicate 'NO' entry\n", ERROR), 0);
		return (handle_no(cfg, f, line + 3));
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (f->parsed_so)
			return (ft_printf_fd(2, "%sDuplicate 'SO' entry\n", ERROR), 0);
		return (handle_so(cfg, f, line + 3));
	}
	return (-1);
}

static int	handle_west_east(char *line, t_config *cfg, t_config_flags *f)
{
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (f->parsed_we)
			return (ft_printf_fd(2, "%sDuplicate 'WE' entry\n", ERROR), 0);
		return (handle_we(cfg, f, line + 3));
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (f->parsed_ea)
			return (ft_printf_fd(2, "%sDuplicate 'EA' entry\n", ERROR), 0);
		return (handle_ea(cfg, f, line + 3));
	}
	return (-1);
}

static int	handle_floor_ceiling(char *line, t_config *cfg, t_config_flags *f)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		if (f->parsed_f)
			return (ft_printf_fd(2, "%sDuplicate 'F' entry\n", ERROR), 0);
		return (handle_floor(cfg, f, line + 2));
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (f->parsed_c)
			return (ft_printf_fd(2, "%sDuplicate 'C' entry\n", ERROR), 0);
		return (handle_ceiling(cfg, f, line + 2));
	}
	return (-1);
}

int	parse_config_line(char *line, t_config *cfg, t_config_flags *flags)
{
	int	result;

	while (*line == ' ' || *line == '\t')
		line++;
	result = handle_north_south(line, cfg, flags);
	if (result != -1)
		return (result);
	result = handle_west_east(line, cfg, flags);
	if (result != -1)
		return (result);
	result = handle_floor_ceiling(line, cfg, flags);
	if (result != -1)
		return (result);
	return (0);
}
