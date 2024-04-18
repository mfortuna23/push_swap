/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:27:27 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/10 19:01:51 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c < 0) || (c > 127))
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int c;

	c = 30;
	ft_isascii(c);
	if (ft_isascii(c) == 1)
		printf("CHAR is ASCII");
	else
		printf("CHAR is NOT ascii");
}
*/
