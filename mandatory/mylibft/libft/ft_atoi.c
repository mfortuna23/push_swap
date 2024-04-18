/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:48:13 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/17 12:09:29 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] != '\0')
	{
		while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i ++;
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i ++] == '-')
				sign = sign * -1;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
			nbr = nbr * 10 + nptr[i ++] - '0';
		if (nptr[i] < '0' || nptr[i] > '9')
			return (nbr * sign);
	}
	return (nbr = 0);
}
