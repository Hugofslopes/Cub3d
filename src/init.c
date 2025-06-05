/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:53:43 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/05 14:00:56 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_textures(t_cub *cub)
{
	cub->textures[0] = cub->config.no_path;
	cub->textures[1] = cub->config.so_path;
	cub->textures[2] = cub->config.we_path;
	cub->textures[3] = cub->config.ea_path;
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
			ft_printf_fd(2, "%s %s \n%s ", CIMAGE, cub->textures[i], CHECKFILE);
			free_exit_textures(cub);
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
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' 
			|| cub->map[i][j] == 'O' || cub->map[i][j] == 'E')
				break ;
			j++;
		}
		i++;
	}
	if (cub->map[i][j])
	{
		cub->player.pos_x = j;
		cub->player.pos_y = i;
	}
}

void	init_player_angle(t_cub *cub)
{
	if (cub->player.start_position == 'N')
		cub->player.angle = 270.0;
	else if (cub->player.start_position == 'S')
		cub->player.angle = 90.0;
	else if (cub->player.start_position == 'E')
		cub->player.angle = 0.0;
	else if (cub->player.start_position == 'W')
		cub->player.angle = 180.0;
}

void	init(t_cub *cub)
{
	cub->game.gamestarted = 0;
	cub->game.cellsize = 3;
	cub->player.speed = 0.3;
	init_player_pos(cub, 0, 0);
	init_player_angle(cub);
	init_mlx(cub);
	init_textures(cub, 0);
	mlx_loop_hook(cub->mlx_s.mlx, build_next_frame, cub);
	mlx_hook(cub->mlx_s.window, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
}
