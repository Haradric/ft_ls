/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:05:46 by mbraslav          #+#    #+#             */
/*   Updated: 2017/04/12 17:05:49 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **list, void const *content, size_t content_size)
{
	t_list	*last;

	if (*list == NULL)
		*list = ft_lstnew(content, content_size);
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = ft_lstnew(content, content_size);
	}
}
