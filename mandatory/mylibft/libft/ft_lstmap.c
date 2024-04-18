/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:15:47 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/30 11:49:14 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new;
	void	*content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		ft_lstadd_back(&new_list, new);
		if (!new)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		lst = lst->next;
	}
	return (new_list);
}
