/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:49:38 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:45:19 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static char	**ft_multipleargs(char **arr, char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
		i++;
	arr = ft_calloc(i, sizeof(char *));
	if (!arr)
		return (0);
	i = i - 2;
	while (i >= 0)
	{
		arr[i] = ft_strdup(argv[i + 1]);
		i--;
	}
	return (arr);
}

void	ft_fillstack(char **arr, t_stack **a, int count)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		stack_addlast(a, ft_atoi(arr[i]));
		i++;
	}
	ft_freearr(arr, count);
	return ;
}

void	ft_createstack(int argc, char **argv, t_stack **a)
{
	char	**arr;
	int		count;

	arr = NULL;
	if (argc == 2)
		arr = ft_nsplit(argv[1]);
	if (argc > 2)
		arr = ft_multipleargs(arr, argv);
	count = countarr(arr);
	if (errorcheck(arr, count) == 1)
		return ;
	ft_fillstack(arr, a, count);
}
