/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:01:20 by mfortuna          #+#    #+#             */
/*   Updated: 2023/10/13 11:10:22 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	ch;
	int				i;

	str = (char *)s;
	ch = (unsigned char)c;
	i = ft_strlen(str);
	if (str[i] == ch)
		return (&str[i]);
	i --;
	while (i >= 0)
	{
		if (str[i] == ch)
			return (&str[i]);
		i --;
	}
	return (NULL);
}
