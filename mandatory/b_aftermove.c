/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_aftermove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:53:44 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/17 10:54:30 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_target_top(t_stack **src, t_stack **dst)
{
	t_stack	*cheap;

	cheap = stack_cheapest(src);
	while (cheap->target_node->current_position != 0)
	{
		if (cheap->target_node->above_median)
		{
			if ((cheap->above_median) && cheap->current_position != 0)
				stack_prerotate(src, dst, "rr");
			else if ((cheap->current_position == 0) || (!cheap->above_median))
				stack_prerotate(dst, src, "ra");
		}
		else if (!cheap->target_node->above_median)
		{
			if ((!cheap->above_median) && cheap->current_position != 0)
				stack_prerevrotate(src, dst, "rrr");
			else if (cheap->current_position == 0 || (cheap->above_median))
				stack_prerevrotate(dst, src, "rra");
		}
		b_aftermove(src, dst);
	}
	return ;
}

void	b_cheap_top(t_stack **src, t_stack **dst)
{
	t_stack	*cheap;

	cheap = stack_cheapest(src);
	while (cheap->current_position != 0)
	{
		if (cheap->above_median)
		{
			if (cheap->target_node->above_median && \
			cheap->target_node->current_position != 0)
				stack_prerotate(dst, src, "rr");
			else
				stack_prerotate(dst, src, "rb");
		}
		else
		{
			if (!cheap->target_node->above_median)
				stack_prerevrotate(dst, src, "rrr");
			else
				stack_prerevrotate(dst, src, "rrb");
		}
		b_aftermove(src, dst);
	}
	stack_push(src, dst, "pa");
	return ;
}

static void	ft_closehigh(t_stack *node, t_stack **head)
{
	t_stack	*high;
	t_stack	*target;
	long	best;

	if ((*head) == NULL)
		return ;
	best = LONG_MAX;
	high = (*head);
	target = NULL;
	while (high)
	{
		if (high->final_index > node->final_index && high->final_index < best)
		{
			best = high->final_index;
			target = high;
		}
		high = high->next;
	}
	node->target_node = target;
	return ;
}

void	b_target(t_stack **src, t_stack **dst)
{
	t_stack	*current;
	int		size;

	if (!(*src) || !(*dst))
		return ;
	current = (*src);
	size = stack_count(src);
	while (size > 0)
	{
		ft_closehigh(current, dst);
		size --;
		if (current->target_node == NULL)
			current->target_node = ft_whoislower(dst);
		current = current->next;
	}
	return ;
}

void	b_aftermove(t_stack **src, t_stack **dst)
{
	stack_currentindex(src);
	stack_currentindex(dst);
	b_target(src, dst);
	stack_pushprice(src, dst);
	stack_cheapest(src);
}
