/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:17:38 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/17 13:04:49 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (n == 0)
		return (s);
	while (src[i] != 0 && ((d + i) < (n - 1)))
	{
		dest[d + i] = src[i];
		i ++;
	}
	dest[d + i] = '\0';
	if (n < d)
		return (s + n);
	return (d + s);
}
