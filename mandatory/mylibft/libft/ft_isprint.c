/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:24 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/13 12:02:22 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c > 31) && (c < 127))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int	c;
	
	c = 30;
	ft_isprint(c);
	if (ft_isprint(c) == 1)
		printf("CHAR is PRINTABLE");
	else
		printf("CHAR is NOT printable");
}
*/
