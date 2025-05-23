/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:27:27 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/23 19:40:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_list;

	tmp_list = lst;
	if (!lst)
		return (NULL);
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	return (tmp_list);
}
