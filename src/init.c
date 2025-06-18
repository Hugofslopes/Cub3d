/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:53:43 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/18 19:27:00 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_textures(t_cub *cub)
{
	cub->textures = malloc(sizeof(char *) * 5);
	if (ft_strnstr(cub->config.no_path, "./", \
		ft_strlen(cub->config.no_path) - 1))
		cub->textures[0] = ft_strtrim(cub->config.no_path, "./");
	else
		cub->textures[0] = ft_strdup(cub->config.no_path);
	if (ft_strnstr(cub->config.so_path, "./", \
		ft_strlen(cub->config.no_path) - 1))
		cub->textures[1] = ft_strtrim(cub->config.so_path, "./");
	else
		cub->textures[1] = ft_strdup(cub->config.so_path);
	if (ft_strnstr(cub->config.we_path, "./", \
		ft_strlen(cub->config.no_path) - 1))
		cub->textures[2] = ft_strtrim(cub->config.we_path, "./");
	else
		cub->textures[2] = ft_strdup(cub->config.we_path);
	if (ft_strnstr(cub->config.ea_path, "./", \
		ft_strlen(cub->config.no_path) - 1))
		cub->textures[3] = ft_strtrim(cub->config.ea_path, "./");
	else
		cub->textures[3] = ft_strdup(cub->config.ea_path);
	cub->textures[4] = NULL;
}

void	init_textures(t_cub *cub, size_t i)
{
	get_textures(cub);
	while (i < 4)
	{
		cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx_s.mlx, \
		cub->textures[i], &cub->texture[i].width, &cub->texture[i].height);
		if (cub->texture[i].img == NULL)
		{
			ft_printf_fd(2, "%s%s %s \n%s ", ERROR, CIMAGE, cub->textures[i], \
				CHECKFILE);
			free_exit_textures(cub, i);
		}
		cub->texture[i].addr = mlx_get_data_addr(cub->texture[i].img, \
		&cub->texture[i].bytes_p_pixel, &cub->texture[i].line_len, \
		&cub->texture[i].endian);
		i++;
	}
}

void	init_player_pos(t_cub *cub, size_t i, size_t j)
{
	while (cub->map[i][j])
	{
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
				cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
				break ;
			j++;
		}
		if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
			cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
		{
			break ;
		}
		j = 0;
		if (cub->map[i][j])
			i++;
	}
	if (cub->map[i][j])
	{
		cub->player.pos_x = j;
		cub->player.pos_y = i;
		cub->player.start_position = cub->map[i][j];
		cub->map[i][j] = '0';
	}
}

void	init_player_angle(t_cub *cub)
{
	if (cub->player.start_position == 'N')
		cub->player.angle = 270.0;
	else if (cub->player.start_position == 'S')
		cub->player.angle = 90.0;
	else if (cub->player.start_position == 'W')
		cub->player.angle = 0.0;
	else if (cub->player.start_position == 'E')
		cub->player.angle = 180.0;
}

void	init(t_cub *cub)
{
	cub->game.gamestarted = 0;
	cub->game.cellsize = 1;
	cub->player.speed = 0.2;
	init_player_pos(cub, 0, 0);
	init_player_angle(cub);
	cub->player.pos_x = cub->player.pos_x * cub->game.cellsize + \
	cub->game.cellsize / 2;
	cub->player.pos_y = cub->player.pos_y * cub->game.cellsize + \
	cub->game.cellsize / 2;
	cub->game.floor = (cub->config.ceiling_color.r << 16) | \
		(cub->config.ceiling_color.g << 8) | cub->config.ceiling_color.b;
	cub->game.ceiling = (cub->config.floor_color.r << 16) | \
		(cub->config.floor_color.g << 8) | cub->config.floor_color.b;
	init_mlx(cub);
	init_textures(cub, 0);
	mlx_loop_hook(cub->mlx_s.mlx, build_next_frame, cub);
	mlx_hook(cub->mlx_s.window, KeyPress, KeyPressMask, key_pressed, cub);
	mlx_hook(cub->mlx_s.window, KeyRelease, KeyRelease, key_released, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
}
