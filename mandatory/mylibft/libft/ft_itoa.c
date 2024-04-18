/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:52:39 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/30 10:58:01 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howmanynbr(int n)
{
	int	countn;

	countn = 1;
	if (n < 0)
	{
		countn ++;
		n = n * -1;
	}
	while (n >= 10)
	{
		countn ++;
		n = n / 10;
	}
	return (countn);
}

static char	*ft_fillthiswithn(char *nbr, int n, int countn)
{
	int	i;

	if (n < 0)
	{
		i = 0;
		nbr[i] = '-';
		ft_fillthiswithn(nbr, n * -1, countn);
		return (nbr);
	}
	if (n >= 10)
	{
		nbr[countn - 1] = n % 10 + 48;
		countn --;
		ft_fillthiswithn (nbr, n / 10, countn);
	}
	else
		nbr[countn - 1] = n + 48;
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		countn;
	int		i;
	char	*nbr;

	if (n == -2147483648)
	{
		i = 0;
		countn = 11;
		nbr = (char *)ft_calloc(countn +1, sizeof(char));
		if (!nbr)
			return (NULL);
		nbr[i ++] = '-';
		nbr[i] = '2';
		return (ft_fillthiswithn(nbr, 147483648, countn));
	}
	countn = ft_howmanynbr(n);
	nbr = (char *)ft_calloc(countn +1, sizeof(char));
	if (!nbr)
		return (NULL);
	return (ft_fillthiswithn(nbr, n, countn));
}
