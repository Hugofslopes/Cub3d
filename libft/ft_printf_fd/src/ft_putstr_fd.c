/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:12:21 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/24 09:00:08 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

size_t	ft_pf_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		ft_pf_putchar_fd(*s++, fd);
		i++;
	}
	return (i);
}
