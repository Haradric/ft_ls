/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:20:44 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 12:20:48 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte	*str1;
	t_byte	*str2;

	str1 = (t_byte *)dst;
	str2 = (t_byte *)src;
	while (n > 0)
	{
		*str1++ = *str2++;
		n--;
	}
	return (dst);
}
