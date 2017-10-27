/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:21:32 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/27 17:21:37 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_byte	*s1;
	t_byte	*s2;

	s1 = (t_byte *)dst;
	s2 = (t_byte *)src;
	if (dst < src)
		while (len--)
			*s1++ = *s2++;
	else
	{
		s1 += len;
		s2 += len;
		while (len--)
			*--s1 = *--s2;
	}
	return (dst);
}
