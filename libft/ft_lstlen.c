/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:14:19 by mbraslav          #+#    #+#             */
/*   Updated: 2016/12/05 15:14:23 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *list)
{
	int		size;
	t_list	*listcpy;

	size = 0;
	listcpy = list;
	while (listcpy != NULL)
	{
		listcpy = listcpy->next;
		size++;
	}
	return (size);
}
