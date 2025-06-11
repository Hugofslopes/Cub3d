/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_validate_open_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:42:51 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/11 12:56:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map_first(t_cub *cub, char *line, char **buffer)
{
	char	*tmp;

	tmp = line;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp && (ft_strncmp(tmp, "NO", 2) || ft_strncmp(tmp, "SO", 2) || \
	ft_strncmp(tmp, "WE", 2) || ft_strncmp(tmp, "EA", 2) || \
	ft_strncmp(tmp, "F", 1) || ft_strncmp(tmp, "C", 1)) && \
	!cub->flags.no_set && !cub->flags.so_set && !cub->flags.we_set && \
	!cub->flags.ea_set && !cub->flags.f_set && !cub->flags.c_set)
	{
		ft_printf_fd(2, "%sFile not starting with textures or colors\n", ERROR);
		free(line);
		free(*buffer);
		exit (1);
	}
}

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
		return (ft_printf_fd(2, "%sPlease check the file name\n", ERROR));
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (ft_printf_fd(2, "%sReading file\n", ERROR), 1);
	return (0);
}

// function to check if it is space.
int	is_space_char(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
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
