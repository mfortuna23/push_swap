/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sortall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:39:49 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 13:43:13 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_pushprice(t_stack **src, t_stack **dst)
{
	int		len_src;
	int		len_dst;
	t_stack	*node;

	if (!(*src) || !(*dst))
		return ;
	node = (*src);
	len_src = stack_count(src);
	len_dst = stack_count(dst);
	while (node)
	{
		node->push_price = node->current_position;
		if (!(node->above_median))
			node->push_price = len_src - node->current_position;
		if (node->target_node->above_median)
			node->push_price += node->target_node->current_position;
		else
			node->push_price += len_dst - (node->target_node->current_position);
		node = node->next;
	}
}

t_stack	*stack_cheapest(t_stack **head)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*current;

	cheapest_node = NULL;
	if (!(*head))
		return (NULL);
	current = (*head);
	cheapest_value = LONG_MAX;
	while (current)
	{
		if (current->push_price < cheapest_value)
		{
			cheapest_value = current->push_price;
			cheapest_node = current;
		}
		current->cheapest = false;
		current = current->next;
	}
	cheapest_node->cheapest = true;
	return (cheapest_node);
}

void	stack_order(t_stack **head)
{
	t_stack	*current;
	t_stack	*compare;

	current = (*head);
	compare = (*head);
	while (current->next != NULL)
	{
		if (compare->next == NULL)
		{
			if (current->data > compare->data)
				current->final_index++;
			compare = (*head);
			current = current->next;
		}
		if (current->data > compare->data)
			current->final_index++;
		compare = compare->next;
	}
	while (compare->next != NULL)
	{
		if (current->data > compare->data)
			current->final_index++;
		compare = compare->next;
	}
	return ;
}

void	stack_currentindex(t_stack **head)
{
	t_stack	*current;
	int		size;
	int		i;
	int		med;

	if (!(*head))
		return ;
	current = (*head);
	size = stack_count(head);
	med = size / 2;
	i = 0;
	while (i <= size)
	{
		current->current_position = i;
		if (i < med)
			current->above_median = true;
		if (i >= med)
			current->above_median = false;
		i++;
		if (current->next == NULL)
			return ;
		current = current->next;
	}
	return ;
}

void	ft_letzsort(t_stack **a, t_stack **b)
{
	stack_push(a, b, "pb");
	if (stack_count(a) > 3)
		stack_push(a, b, "pb");
	while (stack_count(a) > 3)
	{
		a_aftermove(a, b);
		a_target_top(a, b);
		a_cheap_top(a, b);
	}
	if (ft_isitsorted(a) == 1)
		ft_justthree(a, b);
	while ((*b))
	{
		b_aftermove(b, a);
		b_target_top(b, a);
		b_cheap_top(b, a);
	}
	while ((*a)->final_index != 0)
	{
		if (ft_whoislower(a)->above_median)
			stack_prerotate(a, b, "ra");
		else
			stack_prerevrotate(a, b, "rra");
		stack_currentindex(a);
	}
}
