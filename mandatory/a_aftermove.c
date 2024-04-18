/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_aftermove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:59:51 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/17 10:54:07 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_target_top(t_stack **src, t_stack **dst)
{
	t_stack	*cheap;

	cheap = stack_cheapest(src);
	while (cheap->target_node->current_position != 0)
	{
		if (cheap->target_node->above_median)
		{
			if (cheap->above_median && (cheap->current_position != 0))
				stack_prerotate(src, dst, "rr");
			else
				stack_prerotate(src, dst, "rb");
		}
		else if (!cheap->target_node->above_median)
		{
			if (!cheap->above_median)
				stack_prerevrotate(src, dst, "rrr");
			else
				stack_prerevrotate(src, dst, "rrb");
		}
		a_aftermove(src, dst);
	}
	return ;
}

void	a_cheap_top(t_stack **src, t_stack **dst)
{
	t_stack	*cheap;

	cheap = stack_cheapest(src);
	while (cheap->current_position != 0)
	{
		if (cheap->above_median)
		{
			if (cheap->target_node->above_median && \
			cheap->target_node->current_position != 0)
				stack_prerotate(src, dst, "rr");
			else
				stack_prerotate(src, dst, "ra");
		}
		else
		{
			if (!cheap->target_node->above_median)
				stack_prerevrotate(src, dst, "rrr");
			else
				stack_prerevrotate(src, dst, "rra");
		}
		a_aftermove(src, dst);
	}
	if (cheap->target_node->current_position == 0)
		stack_push(src, dst, "pb");
	return ;
}

static void	ft_closelow(t_stack *node, t_stack **head)
{
	t_stack	*low;

	if ((*head) == NULL)
		return ;
	low = (*head);
	node->target_node = NULL;
	while (low)
	{
		if (node->final_index > low->final_index)
		{
			if (node->target_node == NULL)
				node->target_node = low;
			else if ((node->final_index - node->target_node->final_index) > \
			(node->final_index - low->final_index))
				node->target_node = low;
		}
		low = low->next;
	}
	return ;
}

void	a_target(t_stack **src, t_stack **dst)
{
	t_stack	*current;

	if (!(*src) || !(*dst))
		return ;
	current = (*src);
	while (current)
	{
		ft_closelow(current, dst);
		if (current->target_node == NULL)
			current->target_node = ft_whoishigher(dst);
		current = current->next;
	}
	return ;
}

void	a_aftermove(t_stack **src, t_stack **dst)
{
	stack_currentindex(src);
	stack_currentindex(dst);
	a_target(src, dst);
	stack_pushprice(src, dst);
	stack_cheapest(src);
}
