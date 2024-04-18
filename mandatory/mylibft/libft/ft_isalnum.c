/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:55:33 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/10 19:03:22 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < '0') || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || (c > 'z'))
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	c;

	c = 'i';
	ft_isalnum(c);
	if (ft_isalnum(c) == 1)
		printf("CHAR is ALNUM");
	else
		printf("CHAR is NOT alnum");
}
*/
