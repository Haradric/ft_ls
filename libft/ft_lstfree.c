/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:00:43 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/22 18:00:45 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **list, void (*freecont)(void *content))
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if (freecont != NULL)
			freecont((*list)->content);
		free(*list);
		*list = tmp;
	}
}
