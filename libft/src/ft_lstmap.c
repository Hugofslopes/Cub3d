/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:13:25 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/24 08:50:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_list;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		temp_list = ft_lstnew(set);
		if (!temp_list)
		{
			del(set);
			ft_lstclear(&new_list);
			return (new_list);
		}
		ft_lstadd_back(&new_list, temp_list);
		lst = lst->next;
	}
	return (new_list);
}
