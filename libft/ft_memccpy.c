/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:19:11 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 12:19:16 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_byte	*str1;
	t_byte	*str2;

	str1 = (t_byte *)dst;
	str2 = (t_byte *)src;
	while (n > 0)
	{
		*str1 = *str2;
		if (*str2 == (t_byte)c)
			return (str1 + 1);
		str1++;
		str2++;
		n--;
	}
	return (NULL);
}
