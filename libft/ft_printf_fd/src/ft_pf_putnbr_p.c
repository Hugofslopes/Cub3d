/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:47:21 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 20:19:14 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

size_t	ft_pf_putnbr_p_fd(unsigned long n, char *base, int fd)
{
	size_t	numb_char;
	int		array[20];
	size_t	i;

	numb_char = 0;
	if (n == 0)
	{
		ft_pf_putstr_fd("(nil)", fd);
		return (5);
	}
	numb_char += ft_pf_putstr_fd("0x", fd);
	i = 0;
	while (n > 0)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		numb_char += ft_pf_putchar_fd(base[array[--i]], fd);
	return (numb_char);
}
