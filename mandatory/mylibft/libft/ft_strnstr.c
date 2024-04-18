/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:27:45 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/17 12:04:32 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((s1 == s2) || s2[j] == 0)
		return ((char *)s1);
	if (s1[i] == 0 || ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	while (i <= n)
	{
		while (s1[i + j] == s2[j])
		{
			j ++;
			if ((i + j) > n)
				return (NULL);
			if (s2[j] == 0)
				return ((char *)s1 + i);
		}
		j = 0;
		i ++;
	}
	return (NULL);
}
