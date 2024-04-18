/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:09:44 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/17 13:09:45 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*p;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)ft_calloc(sizeof(char), size);
	if (!p)
		return (0);
	ft_memcpy(p, s1, ft_strlen(s1));
	ft_strlcat(p, s2, size);
	return (p);
}
