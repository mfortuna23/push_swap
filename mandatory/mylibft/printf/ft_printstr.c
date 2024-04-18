/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:29:13 by mfortuna          #+#    #+#             */
/*   Updated: 2023/11/14 12:05:26 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_printchar(*s);
		count ++;
		s ++;
	}
	return (count);
}
