/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:43:14 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/13 17:21:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_config_line(char *line, t_cub *cub, char **buffer)
{
	if (!parse_config_line(line, &cub->config, &cub->flags))
	{
		free(line);
		free(*buffer);
		return (1);
	}
	free(line);
	return (0);
}

int	process_line(char *line, t_cub *cub, int *map_started, char **buffer)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!*map_started && (line[i] == '\0' || line[i] == '\n'))
		return (free(line), 0);
	if (!*map_started)
	{
		if (is_config_line(line))
			return (handle_config_line(line, cub, buffer));
		check_map_first(cub, line, buffer);
		if (validate_config(&cub->config))
			return (free(line), free(*buffer), 1);
		if (all_config_flags_set(&cub->flags, &cub->config))
			*map_started = 1;
		else
			return (free(line), free(*buffer), 1);
	}
	if (*map_started && !append_map_line(cub, line))
		return (free(line), free(*buffer), 1);
	free(line);
	return (0);
}

int	handle_map_empty_error(t_cub *cub)
{
	free_array(cub->map);
	cub->map = NULL;
	return (1);
}

int	handle_parse_map_error(t_cub *cub)
{
	free_array(cub->map);
	free_array(cub->map_copy);
	free_config(&cub->config);
	return (1);
}

int	parse_scene_file(int *fd, t_cub *cub)
{
	char	*line;
	char	*buffer;
	int		map_started;

	buffer = NULL;
	map_started = 0;
	line = get_next_line(*fd, &buffer);
	while (line)
	{
		if (process_line(line, cub, &map_started, &buffer))
			return (1);
		line = get_next_line(*fd, &buffer);
	}
	free(buffer);
	if (!cub->config.no_path && !cub->config.so_path && !cub->config.ea_path && \
	!cub->config.we_path && !cub->map)
		return (ft_printf_fd(2, "%sEmpty file or is a folder\n", ERROR), 1);
	if (!cub->map)
		return (ft_printf_fd(2, "%sMissing map\n", ERROR), 1);
	if (!check_map_no_empty_lines(cub->map, 0))
		return (handle_map_empty_error(cub));
	if (parse_map(cub))
		return (handle_parse_map_error(cub));
	return (0);
}
