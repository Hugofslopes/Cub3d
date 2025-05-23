/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:25:49 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 19:41:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**malloc_fails(char **ptr, int i)
{
	char	**new_ptr;

	new_ptr = ptr;
	while (i > 0)
	{
		i--;
		free(*new_ptr++);
	}
	free(ptr);
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	*fill_str(char *word, char const *s, int i, int word_len)
{
	char	*temp;

	temp = word;
	while (word_len > 0)
	{
		*temp++ = s[i - word_len];
		word_len--;
	}
	*temp = '\0';
	return (word);
}

char	**creat_strings(char const *s, char c, char **s2, int n_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < n_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2[word])
			return (malloc_fails(s2, word));
		fill_str(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	n_words;

	if (!s)
		return (0);
	n_words = count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!s2)
		return (0);
	s2 = creat_strings(s, c, s2, n_words);
	return (s2);
}
