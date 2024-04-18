/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:00:29 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/02 11:27:59 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duperror(char **arr, int count)
{
	int	i;
	int	j;
	int	*p;

	p = ft_calloc(count + 1, sizeof(int));
	i = -1;
	j = 0;
	while (arr[++i] != 0)
		p[i] = ft_atoi(arr[i]);
	while (--i >= 0)
	{
		while (j != i)
		{
			if (p[j] == p[i])
			{
				free(p);
				return (1);
			}
			j++;
		}
		j = 0;
	}
	free(p);
	return (0);
}

static int	ft_checkifint(char *s)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[0] == '-')
				sign = -1;
			i++;
		}
		else
		{
			number = (number * 10) + (s[i] - 48);
			i++;
		}
	}
	number *= sign;
	if ((number > 2147483647) || (number < -2147483648))
		return (1);
	return (0);
}

static int	ft_checkifnumber(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			i++;
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		if ((s[0] == '+' || s[0] == '-') && s[1] == 0)
			return (1);
		if (s[i] == 0)
			return (0);
		if (s[i] < '0' || s[i] > '9')
			return (1);
	}
	return (0);
}

int	errorcheck(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr[i] != 0)
	{
		if (ft_checkifnumber(arr[i]) == 1)
		{
			ft_freearr(arr, count);
			return (1);
		}
		if (ft_checkifint(arr[i]) == 1)
		{
			ft_freearr(arr, count);
			return (1);
		}
		i++;
	}
	if (duperror(arr, count) == 1)
	{
		ft_freearr(arr, count);
		return (1);
	}
	return (0);
}
