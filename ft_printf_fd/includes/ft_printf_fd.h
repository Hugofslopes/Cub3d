/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:02:20 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 20:10:57 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define BASE_L "0123456789abcdef"
# define BASE_U "0123456789ABCDEF"

size_t			ft_pf_putnbr_hex_fd(unsigned int n, char *base, int fd);
size_t			ft_pf_putchar_fd(char c, int fd);
size_t			ft_pf_putnbr_fd(int n, int fd);
size_t			ft_pf_putnbr_ui_fd(unsigned int n, int fd);
size_t			ft_pf_putstr_fd(char *str, int fd);
size_t			ft_pf_putnbr_p_fd(unsigned long n, char *base , int fd);

#endif