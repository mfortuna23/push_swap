/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:42:07 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/10 19:03:00 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c < '0') || (c > '9'))
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
int	main (void)
{
	int c;

	c = '5';
	ft_isdigit(c);
	if (ft_isdigit(c) == 1)
		printf("CHAR is DIGIT");
	else
		printf("CHAR is NOT digit");
}
*/
