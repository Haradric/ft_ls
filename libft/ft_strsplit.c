/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:39:19 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/30 13:39:24 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	words_count(char const *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static size_t	word_len(char const *str, char c)
{
	int len;

	len = 0;
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	len;
	int		i;

	if (!s)
		return (NULL);
	if (!(array = (char **)malloc(sizeof(char*) * (words_count(s, c) + 1))))
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_len(s, c);
			array[i] = ft_strnew(len);
			ft_strncpy(array[i++], s, len);
			s += len;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	array[i] = NULL;
	return (array);
}
