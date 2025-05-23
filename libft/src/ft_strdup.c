/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:33:57 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 19:41:59 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *s)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (s[i] != '\0')
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
