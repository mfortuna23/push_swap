/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:36:30 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/29 13:10:37 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	ft_createstack(argc, argv, &a);
	if (!a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_order(&a);
	if (ft_isitsorted(&a) == 1)
		ft_sort(&a);
	stack_bomb(&a);
	return (0);
}
