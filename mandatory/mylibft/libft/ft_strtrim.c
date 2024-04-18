/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:10:04 by mfortuna          #+#    #+#             */
/*   Updated: 2023/11/03 12:08:31 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	f;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	f = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i ++;
	while (s1[i] && ft_strchr(set, s1[f]))
		f --;
	return (ft_substr(s1, i, (f - i) + 1));
}
/*
#include <stdio.h>
int main(void)
{
	char	s1[]="jhyduhfbkejhy kduihnyhj";
	char	set[]="jhy";

	printf("%s \n", ft_strtrim(s1, set));
}
*/