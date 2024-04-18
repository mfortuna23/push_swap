/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:07:58 by mfortuna          #+#    #+#             */
/*   Updated: 2023/11/06 15:37:31 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countmywords(const char	*s, char c)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count ++;
			while ((s[i]) && s[i] != c)
				i ++;
		}
		else
			i ++;
	}
	return (count);
}

static char	**ft_freearr(char	**arr, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**toomanylines(char **arr, char *s, char c, size_t word)
{
	size_t	i;
	size_t	j;
	size_t	x;

	x = 0;
	i = 0;
	while (word - 1 > x && s[i] != 0)
	{
		while (s[i] == c)
			i ++;
		j = i;
		while (s[i] != c && s[i] != 0)
			i ++;
		if ((s[i] == c || s[i] == 0) && word - 1 > x)
		{
			arr[x] = ft_substr(s, j, (i - j) * sizeof(char));
			if (!arr[x])
				return (ft_freearr(arr, word));
			i ++;
			x ++;
		}
	}
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	word;

	if (!s)
		return (0);
	word = ft_countmywords(s, c);
	arr = (char **)ft_calloc(word, sizeof(char *));
	if (!arr)
		return (0);
	return (toomanylines(arr, (char *)s, c, word));
}
