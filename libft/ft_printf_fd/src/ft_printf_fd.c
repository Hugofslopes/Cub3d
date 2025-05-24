/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 08:58:57 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/24 08:59:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_fd.h"

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	size_t	numb_char;
	char	*s;

	numb_char = 0;
	va_start(args, str);
	s = (char *)str;
	while (*s)
	{
		if (*s == '%')
			numb_char += select_formats(args, &s, fd);
		if (*s && *s != '%')
			numb_char += ft_pf_putchar_fd(*s++, fd);
	}
	va_end(args);
	return (numb_char);
}

size_t	select_formats(va_list args, char **format, int fd)
{
	size_t	numb_char;

	numb_char = 0;
	(*format)++;
	if (**format == 'c')
		numb_char += ft_pf_putchar_fd(va_arg(args, int), fd);
	else if (**format == 's')
		numb_char += ft_pf_putstr_fd(va_arg(args, char *), fd);
	else if (**format == 'p')
		numb_char += ft_pf_putnbr_p_fd(va_arg(args, unsigned long), \
		BASE_L, fd);
	else if (**format == 'd' || **format == 'i')
		numb_char += ft_pf_putnbr_fd(va_arg(args, int), fd);
	else if (**format == 'u')
		numb_char += ft_pf_putnbr_ui_fd(va_arg(args, unsigned int), fd);
	else if (**format == 'x')
		numb_char += ft_pf_putnbr_hex_fd(va_arg(args, unsigned long), \
		BASE_L, fd);
	else if (**format == 'X')
		numb_char += ft_pf_putnbr_hex_fd(va_arg(args, unsigned long), \
		BASE_U, fd);
	else if (**format == '%')
		numb_char += ft_pf_putchar_fd('%', fd);
	return (numb_char);
}
