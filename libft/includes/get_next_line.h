/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:49:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 11:45:18 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd, char **strgs);
int		copy_fd(int fd, char **strgs);
void	add_to_strgs(char *buffer, char ***strgs);
char	*verify_newline(char **strgs);
char	*realloc_strgs(char *strgs, size_t len);
char	*trim_strgs(char *strgs, size_t len, size_t i);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*alloc_for_nl(size_t j, size_t len, char **strgs);
int		check_for_newline(char ***strgs);
#endif
