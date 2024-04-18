/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:43:01 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/30 15:22:04 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*new;
	int		count;

	new = lst;
	count = 0;
	while (new != NULL)
	{
		new = new->next;
		count ++;
	}
	return (count);
}
/*
#include "stdio.h"
int	main(void)
{
	t_list	*test;
	t_list	*node;

	node = ft_lstnew("kjdeir");
	test = node;
	node->next = ft_lstnew("kj");
	node = node->next;
	node->next = ft_lstnew("kj");
	node = node->next;
	node->next = ft_lstnew("kj");
	node = node->next;
	node->next = ft_lstnew("kj");
	node = node->next;
	node->next = ft_lstnew("kj");
	printf("%d\n", ft_lstsize(test));
}
*/