/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:17:34 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/14 08:22:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_invalid_chars(char *map, size_t j)
{
	while (map[j])
	{
		if (ft_isdigit(map[j]) && map[j] != '0' && map[j] != '1')
		{
			ft_printf_fd(2, "%sInvalid map char: '%c'\n", ERROR, map[j]);
			return (1);
		}
		else if (ft_isalpha(map[j]) && (map[j] != 'W' && map[j] != 'E' && \
		map[j] != 'S' && map[j] != 'N'))
		{
			ft_printf_fd(2, "%sInvalid map char: '%c'\n", ERROR, map[j]);
			return (1);
		}
		else if (ft_isascii(map[j]) && !ft_isalpha(map[j]) && \
		!ft_isdigit(map[j]) && map[j] != '\n' && map[j] != '\t' && \
		map[j] != ' ')
		{
			ft_printf_fd(2, "%sInvalid map char: '%c'\n", ERROR, map[j]);
			return (1);
		}
		else
			j++;
	}
	return (0);
}

int	check_map_no_empty_lines2(char **map, size_t *i)
{
	while (map && map[*i] && (ft_strchr(map[*i], ' ') || \
	ft_strchr(map[*i], '\t') || map[*i][0] == '\0') && \
	!ft_strchr(map[*i], '1') && !ft_strchr(map[*i], '0'))
	{
		if (check_invalid_chars(map[*i], 0))
			return (0);
		(*i)++;
	}
	while (map && map[*i] && (ft_strchr(map[*i], '1') || \
	ft_strchr(map[*i], '0') || ft_strchr(map[*i], 'N') || \
	ft_strchr(map[*i], 'S') || ft_strchr(map[*i], 'W') \
	|| ft_strchr(map[*i], 'E')))
	{
		if (check_invalid_chars(map[*i], 0))
			return (0);
		(*i)++;
	}
	if (!map[*i])
		return (1);
	return (1);
}

int	check_map_no_empty_lines(char **map, size_t i)
{
	if (check_invalid_chars(map[i], 0))
		return (0);
	if (!check_map_no_empty_lines2(map, &i))
		return (0);
	while (map && map[i] && (ft_strchr(map[i], ' ') || ft_strchr(map[i], '\t') \
	|| map[i][0] == '\0') && !ft_strchr(map[i], '1') && !ft_strchr(map[i], '0'))
	{
		if (check_invalid_chars(map[i], 0))
			return (0);
		i++;
	}
	if (!map[i])
		return (1);
	else if (check_invalid_chars(map[i], 0))
		return (0);
	else
		return (ft_printf_fd(2, "%s%s", ERROR, EMPTYL), 0);
	return (0);
}
