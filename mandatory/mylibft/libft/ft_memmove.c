/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:32:56 by mfortuna          #+#    #+#             */
/*   Updated: 2023/11/03 12:35:42 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	else if ((unsigned char *)src > (unsigned char *)dest && n > 0)
		ft_memcpy(dest, src, n);
	else if ((unsigned char *)src < (unsigned char *)dest && n > 0)
	{
		i = n - 1;
		while (i > 0)
		{
			d[i] = s[i];
			i--;
		}
		d[i] = s[i];
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
    char str2[7]="osj";
    char str1[]="osKBOimtHTYNIr3";

    ft_memmove(str2, str1, 3);
    printf("%s \n %p  %p\n", str2, str1, str2);
}
*/
