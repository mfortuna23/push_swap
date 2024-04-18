/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:52:35 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:33:58 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*first;

	if ((*head == NULL) || head == NULL || (stack_count(head) == 1))
		return (1);
	last = *head;
	first = *head;
	while (last->next != NULL)
		last = last->next;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
	return (0);
}

static int	stack_revrotate(t_stack **head)
{
	t_stack	*last;

	if ((*head == NULL) || head == NULL || (stack_count(head) == 1))
		return (1);
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	(*head)->prev = last;
	*head = last;
	return (0);
}

void	stack_prerotate(t_stack **a, t_stack **b, char *s)
{
	int	check;
	int	bcheck;

	check = 0;
	bcheck = 0;
	if (s[1] == 'a')
		check = stack_rotate(a);
	else if (s[1] == 'b')
		check = stack_rotate(b);
	else if (s[1] == 'r')
	{
		check = stack_rotate(a);
		bcheck = stack_rotate(b);
		if ((check + bcheck) == 2)
			return ;
		check = check - bcheck;
		if (check == 1)
			ft_printf("rb\n");
		if (check == -1)
			ft_printf("ra\n");
	}
	if (check == 0)
		ft_printf("%s\n", s);
	return ;
}

void	stack_prerevrotate(t_stack **a, t_stack **b, char *s)
{
	int	check;
	int	bcheck;

	check = 0;
	bcheck = 0;
	if (s[2] == 'a')
		check = stack_revrotate(a);
	else if (s[2] == 'b')
		check = stack_revrotate(b);
	else if (s[2] == 'r')
	{
		check = stack_revrotate(a);
		bcheck = stack_revrotate(b);
		if ((check + bcheck) == 2)
			return ;
		check = check - bcheck;
		if (check == 1)
			ft_printf("rb\n");
		if (check == -1)
			ft_printf("ra\n");
	}
	if (check == 0)
		ft_printf("%s\n", s);
	return ;
}
