/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:20:02 by mbraslav          #+#    #+#             */
/*   Updated: 2016/11/26 12:20:09 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*p;
	t_byte	chr;
	t_byte	i;

	p = (t_byte *)s;
	chr = (t_byte)c;
	i = 0;
	while (i < n)
	{
		if (*(p + i) == chr)
			return (p + i);
		i++;
	}
	return (0);
}
