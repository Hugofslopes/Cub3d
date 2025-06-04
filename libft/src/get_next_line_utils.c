/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:58:55 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/03 20:20:43 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*alloc_for_nl(size_t j, size_t len, char **strgs)
{
	char	*temp;
	size_t	i;

	if ((*strgs) == NULL || **strgs == '\0')
		return (NULL);
	//if ((*strgs) == NULL)
	//	return (malloc(0));
	i = 0;
	temp = ft_calloc((j + 2), sizeof(char));
	while ((*strgs)[i])
	{
		temp[i] = (*strgs)[i];
		if (temp[i++] == '\n')
			break ;
	}
	temp[i] = '\0';
	len -= i;
	if (len <= 0)
	{
		free(*strgs);
		*strgs = NULL;
		return (temp);
	}
	*strgs = trim_strgs(*strgs, len, i);
	return (temp);
}

char	*verify_newline(char **strgs)
{
	size_t	len;
	size_t	j;
	char	*temp;

	j = 0;
	if (*strgs == NULL || **strgs == '\0')
		return (NULL);
	//if (*strgs == NULL)
	//	return (malloc(0));
	len = ft_strlen(*strgs);
	while ((*strgs)[j] != '\0')
	{
		if ((*strgs)[j] == '\n' || len <= 1)
			break ;
		j++;
	}
	temp = alloc_for_nl(j, len, strgs);
	return (temp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;
	size_t	i;
	char	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_bytes = nmemb * size;
	if ((total_bytes / size) != nmemb)
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	str = (char *)ptr;
	while (i < total_bytes)
		str[i++] = '\0';
	return (ptr);
}

int	check_for_newline(char ***strgs)
{
	size_t	i;

	i = 0;
	while ((**strgs)[i])
	{
		if ((**strgs)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
