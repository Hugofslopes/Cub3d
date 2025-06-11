/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_dup_check_map_cells.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:41:39 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/11 09:41:44 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_map_chars_support(t_cub *cub, int *count, t_pos_info *pos)
{
	if (!ft_strchr("10NSEWX", pos->c))
		return (ft_printf_fd(2, "%sNot allowed char was found\n", ERROR), 1);
	if (pos->c == 'N' || pos->c == 'S' || pos->c == 'E' || pos->c == 'W')
	{
		cub->player_x = pos->j;
		cub->player_y = pos->i;
		(*count)++;
	}
	if (*count > 1)
		return (ft_printf_fd(2, "%sMore than one player found\n", ERROR), 1);
	return (0);
}

int	validate_map_chars(t_cub *cub)
{
	int			i;
	int			j;
	int			count;
	t_pos_info	pos;

	i = 0;
	count = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			pos.i = i;
			pos.j = j;
			pos.c = cub->map[i][j];
			if (validate_map_chars_support(cub, &count, &pos))
				return (1);
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_printf_fd(2, "%sNo player found\n", ERROR), 1);
	return (0);
}

void	dup_map(t_cub *cub)
{
	int	i;

	i = 0;
	cub->map_copy = malloc(sizeof(char *) * (cub->map_height + 1));
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
	cub->map_copy[i] = NULL;
}

void	init_visited(t_cub *cub, int ***visited)
{
	int	i;
	int	j;

	i = 0;
	*visited = malloc(sizeof(int *) * cub->map_height);
	if (!*visited)
		exit(1);
	while (i < cub->map_height)
	{
		(*visited)[i] = malloc(sizeof(int) * ft_strlen(cub->map_copy[i]));
		if (!(*visited)[i])
			exit(1);
		j = 0;
		while (j < (int)ft_strlen(cub->map_copy[i]))
		{
			(*visited)[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	check_unreachable_cells(t_cub *cub, int **visited)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(cub->map_copy[y]))
		{
			c = cub->map_copy[y][x];
			if ((c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				&& !visited[y][x])
			{
				ft_printf_fd(2, "%sUnreachable map cell\n", ERROR);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
