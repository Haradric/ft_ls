/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:05:06 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/06 19:05:08 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_elem_in_list(t_list *list, t_list *elem)
{
	t_list	*last;

	if (list == NULL || elem == NULL)
		return (0);
	last = list;
	while (last)
	{
		if (last == elem)
			return (1);
		last = last->next;
	}
	return (0);
}

static t_list	*find_prev_elem(t_list *list, t_list *elem)
{
	t_list	*last;
	t_list	*prev_elem;

	if (list == NULL || elem == NULL || !is_elem_in_list(list, elem))
		return (NULL);
	last = list;
	prev_elem = NULL;
	while (last != elem)
	{
		prev_elem = last;
		last = last->next;
	}
	return (prev_elem);
}

void			ft_lstswap(t_list **list, t_list *x, t_list *y)
{
	t_list	*prev_x;
	t_list	*prev_y;
	t_list	*tmp;

	if (x == y || !is_elem_in_list(*list, x) || !is_elem_in_list(*list, y))
		return ;
	prev_x = find_prev_elem(*list, x);
	prev_y = find_prev_elem(*list, y);
	if (prev_x != NULL)
		prev_x->next = y;
	else
		*list = y;
	if (prev_y != NULL)
		prev_y->next = x;
	else
		*list = x;
	tmp = y->next;
	y->next = x->next;
	x->next = tmp;
}
