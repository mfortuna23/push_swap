/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:30:17 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:32:06 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack **src, t_stack **dst, char *s)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dst == NULL)
	{
		*dst = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dst;
		node->next->prev = node;
		*dst = node;
	}
	ft_printf("%s\n", s);
	return ;
}

static int	stack_swap(t_stack **head)
{
	if ((*head == NULL) || head == NULL || (stack_count(head) == 1))
		return (1);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	stack_preswap(t_stack **a, t_stack **b, char *s)
{
	int	check;
	int	bcheck;

	check = 0;
	bcheck = 0;
	if (s[1] == 'a')
		check = stack_swap(a);
	else if (s[1] == 'b')
		check = stack_swap(b);
	else if (s[1] == 's')
	{
		check = stack_swap(a);
		bcheck = stack_swap(b);
		if ((check + bcheck) == 2)
			return ;
		check = check - bcheck;
		if (check == 1)
			ft_printf("sb\n");
		if (check == -1)
			ft_printf("sa\n");
	}
	if (check == 0)
		ft_printf("%s\n", s);
	return ;
}
