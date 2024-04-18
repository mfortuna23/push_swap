/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:12:08 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/10 16:23:09 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char str1[]="123456";
	char str2[]="2146";
	char str3[]="123456";
	char str4[]="2146";

	memcpy(str1, str2, 3);
	printf("%s \n", str1);
	ft_memcpy(str3, str4, 3);
	printf("%s \n", str3);
}
*/