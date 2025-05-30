/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:00:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/30 21:01:12 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**test_array(t_cub *cub)
{
	char	**test;

	test = malloc(sizeof(char *) * 9);
	test[0] = "11111111";
	test[1] = "10000001";
	test[2] = "10011001";
	test[3] = "10011001";
	test[4] = "10100001";
	test[5] = "10111101";
	test[6] = "10000001";
	test[7] = "11111111";
	test[8] = NULL;
	cub->player.start_position = 'S';
	cub->textures = malloc(sizeof(char *) * 5);
	cub->textures[0] = "textures/N";
	cub->textures[1] = "textures/S";
	cub->textures[2] = "textures/E";
	cub->textures[3] = "textures/W";
	cub->textures[4] = NULL;
	cub->ceiling.r = 20;
	cub->ceiling.g = 2;
	cub->ceiling.b = 10;
	cub->floor.r = 2;
	cub->floor.g = 20;
	cub->floor.b = 20;
	cub->player.pos_x = 1 * cub->game.cellsize + cub->game.cellsize / 2;
	cub->player.pos_y = 1 * cub->game.cellsize + cub->game.cellsize / 2;
	cub->game.map_with = 8;
	cub->game.map_height = 8;
	return (test);
}
