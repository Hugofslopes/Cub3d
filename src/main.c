/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:43:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/05 19:56:44 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(cub));
	if (handle_input(ac, av, &cub))
		return (1);
	init(&cub);
	return (0);
}
