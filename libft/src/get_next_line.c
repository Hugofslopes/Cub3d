/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:51:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/09 09:29:03 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*trim_strgs(char *strgs, size_t len, size_t i)
{
	char	*new_ptr;
	size_t	j;

	j = 0;
	new_ptr = ft_calloc((len + 1), sizeof(char));
	if (!new_ptr)
		return (NULL);
	if (strgs != NULL)
	{
		while (strgs[i])
		{
			new_ptr[j] = strgs[i];
			i++;
			j++;
		}
		free(strgs);
		new_ptr[j] = '\0';
	}
	return (new_ptr);
}

char	*realloc_strgs(char *strgs, size_t len)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = ft_calloc((len + 1), sizeof(char));
	if (!new_ptr)
		return (NULL);
	i = 0;
	if (strgs != NULL)
	{
		while (strgs[i])
		{
			new_ptr[i] = strgs[i];
			i++;
		}
		free(strgs);
		new_ptr[i] = '\0';
	}
	return (new_ptr);
}

void	add_to_strgs(char *buffer, char ***strgs)
{
	size_t	len1;
	char	*temp;
	size_t	j;

	if (!buffer)
		return ;
	if (**strgs == NULL || ***strgs == '\0')
		len1 = 0;
	else
		len1 = ft_strlen(**strgs);
	temp = realloc_strgs(**strgs, len1 + ft_strlen(buffer));
	if (!temp)
		return ;
	j = 0;
	**strgs = temp;
	while (*temp)
		temp++;
	while (buffer[j])
	{
		temp[j] = buffer[j];
		j++;
	}
	temp[j] = '\0';
	free(buffer);
}

int	copy_fd(int fd, char **strgs)
{
	char			*buffer;
	int				char_readed;

	char_readed = 1;
	while (char_readed > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (0);
		char_readed = read(fd, buffer, BUFFER_SIZE);
		if (char_readed <= 0)
		{
			free(buffer);
			return (1);
		}
		else if (buffer == NULL || buffer[0] == '\0')
		{
			free(buffer);
			return (0);
		}
		add_to_strgs(buffer, &strgs);
		if (check_for_newline(&strgs))
			return (1);
	}
	return (1);
}

char	*get_next_line(int fd, char **strgs)
{
	char			*next_line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	i = copy_fd(fd, strgs);
	if (!i || !strgs || *strgs == NULL || **strgs == '\0')
		return (NULL);
	next_line = verify_newline(strgs);
	return (next_line);
}
