/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:29:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/31 10:29:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**test_array(t_cub *cub);

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

void	init_textures(t_cub *cub, size_t i)
{
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

void	init(t_cub *cub)
{
	cub->game.gamestarted = 0;
	cub->game.cellsize = 3;
	cub->player.speed = 0.3;
	cub->map = test_array(cub);
	init_player_angle(cub);
	init_mlx(cub);
	init_keys(cub, 0);
	init_textures(cub, 0);
	mlx_loop_hook(cub->mlx_s.mlx, build_next_frame, cub);
	mlx_hook(cub->mlx_s.window, 2, 1L << 0, key_pressed, cub);
	mlx_hook(cub->mlx_s.window, 17, 0, mouse_close, cub);
	mlx_loop(cub->mlx_s.mlx);
}
