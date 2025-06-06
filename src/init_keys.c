/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:56:20 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/06 16:13:50 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	test_key_files(t_cub *cub, char **key)
{
	int		fd;
	size_t	i;

	i = 0;
	while (i < 12)
	{
		fd = open(key[i], O_RDONLY);
		if (fd == -1)
		{
			ft_printf_fd(2, "%s %s \n%s ", IFILE, key[i], CHECKFILE);
			free_exit_keys(cub);
		}
		else
			close (fd);
		i++;
	}
	return (0);
}

void	init_keys2(t_cub *cub, size_t i, char **key)
{
	while (i < 12)
	{
		cub->keys[i].img = mlx_xpm_file_to_image(cub->mlx_s.mlx, \
		key[i], &cub->keys[i].width, &cub->keys[i].height);
		if (cub->keys[i].img == NULL)
			return (ft_printf_fd(2, "%s %s \n%s ", CIMAGE, key[i], CHECKFILE), \
			free_exit_keys(cub));
		cub->keys[i].addr = mlx_get_data_addr(cub->keys[i].img, \
		&cub->keys[i].bytes_p_pixel, &cub->keys[i].line_len, \
		&cub->keys[i].endian);
		i++;
	}
}

void	init_keys(t_cub *cub, size_t i)
{
	char	*key[12];

	key[0] = "keys/fr";
	key[1] = "keys/bc";
	key[2] = "keys/lf";
	key[3] = "keys/rt";
	key[4] = "keys/bs";
	key[5] = "keys/rl";
	key[6] = "keys/rr";
	key[7] = "keys/lr";
	key[8] = "keys/bo";
	key[9] = "keys/la";
	key[10] = "keys/ra";
	key[11] = "keys/do";
	test_key_files(cub, key);
	init_keys2(cub, i, key);
}
