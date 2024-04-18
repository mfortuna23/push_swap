/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:27:39 by mfortuna          #+#    #+#             */
/*   Updated: 2023/11/14 12:06:19 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_nbr(long n, int base)
{
	int	countn;

	countn = 1;
	if (n < 0)
	{
		countn ++;
		n = n * -1;
	}
	while (n >= base)
	{
		countn ++;
		n = n / base;
	}
	return (countn);
}

static int	ft_printp(unsigned long n, unsigned int base)
{
	char	*sym;
	int		countn;

	countn = 1;
	sym = "0123456789abcdef";
	if (n >= base)
	{
		ft_printp(n / base, base);
		ft_printp(n % base, base);
	}
	else
		ft_printchar(sym[n]);
	while (n >= base)
	{
		countn ++;
		n = n / base;
	}
	return (countn);
}

static int	ft_printnbr(long n, unsigned int base)
{
	char	*sym;
	int		countn;

	countn = ft_count_nbr(n, base);
	sym = "0123456789abcdef";
	if (n < 0)
	{
		ft_printchar('-');
		n = n * -1;
	}
	if (n >= base)
	{
		ft_printnbr(n / base, base);
		ft_printnbr(n % base, base);
	}
	else
		ft_printchar(sym[n]);
	return (countn);
}

static int	ft_printx(long n, unsigned int base)
{
	char	*sym;
	int		countn;

	countn = ft_count_nbr(n, base);
	sym = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_printchar('-');
		n = n * -1;
	}
	if (n >= base)
	{
		ft_printx(n / base, base);
		ft_printx(n % base, base);
	}
	else
		ft_printchar(sym[n]);
	return (countn);
}

int	ft_nbr(const char *s, va_list args)
{
	unsigned long	n;

	if (*s == 'd' || *s == 'i')
		return (ft_printnbr((long)va_arg(args, int), 10));
	if (*s == 'u')
		return (ft_printnbr((long)va_arg(args, unsigned int), 10));
	if (*s == 'x')
		return (ft_printnbr((long)va_arg(args, unsigned int), 16));
	if (*s == 'X')
		return (ft_printx((long)va_arg(args, unsigned int), 16));
	if (*s == 'p')
	{
		n = va_arg(args, unsigned long);
		if (!n)
			return (ft_printstr("(nil)"));
		ft_printchar('0');
		ft_printchar('x');
		return (ft_printp(n, 16) + 2);
	}
	return (0);
}
