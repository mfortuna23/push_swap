/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:12:42 by mfortuna          #+#    #+#             */
/*   Updated: 2023/11/14 12:09:26 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sign(const char *s, va_list args, int count)
{
	char	*str;

	++s;
	if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
		|| *s == 'X' || *s == 'p')
		return (ft_nbr(s, args));
	else if (*s == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (*s == 's')
	{
		str = (va_arg(args, char *));
		if (!str)
			return (ft_printstr("(null)"));
		else
			return (ft_printstr(str));
	}
	else if (*s == '%')
		return (ft_printchar('%'));
	else
	{
		ft_printchar('%');
		ft_printchar(*s);
		count = 2;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		n;

	va_start(args, s);
	n = 0;
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			n += ft_sign(s, args, count);
			s++;
		}
		else
			n += ft_printchar(*s);
		s ++;
	}
	return (n);
}

// #include <stdio.h>
// int main (void)
// {
// 	// char s[]="em hexadecimal";
// 	// int x = 500525;
// 	int n;
// 	// printf("NULL %s NULL", NULL);
// 	printf(" %p ", 9223372036854775807);
// 	n = ft_printf(" %p ", -4294967295);
// 	printf("numero de char impressos: %d \n", n);
// }
