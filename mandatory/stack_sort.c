/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:10 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:34:28 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_whoislower(t_stack **head)
{
	t_stack	*current;
	t_stack	*low;
	int		data;

	current = (*head);
	low = current;
	data = current->data;
	while (current)
	{
		if (data > current->data)
		{
			data = current->data;
			low = current;
		}
		current = current->next;
	}
	return (low);
}

t_stack	*ft_whoishigher(t_stack **head)
{
	t_stack	*current;
	t_stack	*high;
	int		data;

	current = (*head);
	high = current;
	data = current->data;
	while (current)
	{
		if (data < current->data)
		{
			data = current->data;
			high = current;
		}
		current = current->next;
	}
	return (high);
}

void	ft_justthree(t_stack **head, t_stack **b)
{
	t_stack	*current;

	current = ft_whoishigher(head);
	if (current->next == NULL)
		stack_preswap(head, b, "sa");
	else if (current->prev == NULL)
		stack_prerotate(head, b, "ra");
	else if (current->prev != NULL && current->next != NULL)
		stack_prerevrotate(head, b, "rra");
	if (ft_isitsorted(head) == 1)
		ft_justthree(head, b);
	return ;
}

void	ft_sort(t_stack **a)
{
	int		size;
	t_stack	*b;

	b = NULL;
	size = stack_count(a);
	if (size == 2)
		stack_preswap(a, &b, "sa");
	else if (size == 3)
		ft_justthree(a, &b);
	else
		ft_letzsort(a, &b);
	return ;
}

int	ft_isitsorted(t_stack **a)
{
	int		value1;
	int		value2;
	t_stack	*tmp;

	tmp = (*a);
	if (stack_count(a) == 1)
		return (0);
	while (tmp->next != NULL)
	{
		value1 = tmp->final_index;
		tmp = tmp->next;
		value2 = tmp->final_index;
		if (value1 > value2)
			return (1);
	}
	return (0);
}
