/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:38:52 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:44:39 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_countmywords(const char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] > 32)
		{
			count ++;
			while (s[i] > 32)
				i ++;
		}
		else
			i ++;
	}
	return (count);
}

char	**ft_freearr(char	**arr, size_t word)
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

static char	**toomanylines(char **arr, char *s, size_t word)
{
	size_t	i;
	size_t	j;
	size_t	x;

	x = 0;
	i = 0;
	while (word > x && s[i] != 0)
	{
		while (s[i] < 33)
			i ++;
		j = i;
		while (s[i] > 33)
			i ++;
		if ((s[i] < 33) && word > x)
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

char	**ft_nsplit(const char *s)
{
	char	**arr;
	size_t	word;

	if (!s)
		return (0);
	word = ft_countmywords(s);
	arr = (char **)ft_calloc(word + 1, sizeof(char *));
	if (!arr)
		return (0);
	return (toomanylines(arr, (char *)s, word));
}
