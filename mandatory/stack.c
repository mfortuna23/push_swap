/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:03:31 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:31:40 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_createnode(int value)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->final_index = 0;
	newnode->target_node = NULL;
	newnode->cheapest = false;
	return (newnode);
}

void	stack_addlast(t_stack **head, int value)
{
	t_stack	*newnode;
	t_stack	*current;

	newnode = stack_createnode(value);
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	current = (*head);
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
	newnode->prev = current;
}

void	stack_deletelast(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*head) == NULL)
		return ;
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	free(last);
	return ;
}

void	stack_bomb(t_stack **head)
{
	while (*head != NULL)
		stack_deletelast(head);
	return ;
}

int	stack_count(t_stack **head)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = *head;
	while (current != NULL)
	{
		count ++;
		current = current->next;
	}
	return (count);
}
