/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:20:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 20:14:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

size_t	ft_pf_putnbr_fd(int n, int fd)
{
	long int	numb;
	size_t		numb_char;
	char		array[20];
	size_t		i;

	numb = n;
	i = 0;
	numb_char = 0;
	if (numb < 0)
	{
		numb_char += ft_pf_putchar_fd('-', fd);
		numb = -numb;
	}
	if (numb == 0)
		array[i++] = 48;
	while (numb > 0)
	{
		array[i++] = (numb % 10) + '0';
		numb /= 10;
	}
	while (i > 0)
		numb_char += ft_pf_putchar_fd(array[--i], fd);
	return (numb_char);
}
