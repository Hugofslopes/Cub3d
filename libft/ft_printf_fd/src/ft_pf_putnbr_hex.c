/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:20:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 20:19:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

size_t	ft_pf_putnbr_hex_fd(unsigned int n, char *base, int fd)
{
	size_t	numb_char;
	int		array[8];
	size_t	i;

	pf_bzero(array, 8);
	numb_char = 0;
	i = 0;
	if (n == 0)
		return (ft_pf_putchar_fd('0', 1));
	while (n > 0 && i <= 7)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		numb_char += ft_pf_putchar_fd(base[array[--i]], fd);
	return (numb_char);
}
