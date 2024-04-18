/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:46:16 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/16 10:42:06 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	if (!n)
		return (NULL);
	while (i < n - 1)
	{
		if (str[i] == ch)
			return (&str[i]);
		i ++;
	}
	if (str[i] == ch)
		return (&str[i]);
	return (NULL);
}
