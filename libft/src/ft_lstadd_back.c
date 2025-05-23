/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:07 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 19:40:13 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new1)
{
	t_list	*temp_list;

	if (!new1)
		return ;
	if (!*lst)
	{
		*lst = new1;
		return ;
	}
	temp_list = ft_lstlast(*lst);
	temp_list->next = new1;
}
