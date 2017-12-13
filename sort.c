/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:39:28 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:39:29 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort(t_list **list, t_opt *flags)
{
	if (flags->t == 1)
	{
		if (flags->r == 1)
			lstrsort(list, cmp_time);
		else
			lstsort(list, cmp_time);
	}
	else if (flags->sb == 1)
	{
		if (flags->r == 1)
			lstrsort(list, cmp_size);
		else
			lstsort(list, cmp_size);
	}
	else
	{
		if (flags->r == 1)
			lstrsort(list, cmp_name);
		else
			lstsort(list, cmp_name);
	}
}

static void lstswap(t_list *elem1, t_list *elem2)
{
	void	*p_tmp;
	size_t	i_tmp;

	p_tmp = elem1->content;
	i_tmp = elem1->content_size;
	elem1->content = elem2->content;
	elem1->content_size = elem2->content_size;
	elem2->content = p_tmp;
	elem2->content_size = i_tmp;
}

void	lstsort(t_list **list, int (*cmp)(void *a, void *b))
{
	t_list	*sorted;
	t_list	*last;
	int		swapped;

	swapped = 1;
	sorted = NULL;
	while (swapped == 1)
	{
		swapped = 0;
		last = *list;
		while (last->next)
		{
			if (cmp(last, last->next) > 0)
			{
				lstswap(last, last->next);
				swapped = 1;
			}
			if (last->next == NULL || last->next == sorted)
			{
				sorted = last;
				continue ;
			}
			last = last->next;
		}
	}
}

void	lstrsort(t_list **list, int (*cmp)(void *a, void *b))
{
	t_list	*sorted;
	t_list	*last;
	int		swapped;

	swapped = 1;
	sorted = NULL;
	while (swapped == 1)
	{
		swapped = 0;
		last = *list;
		while (last->next)
		{
			if (cmp(last, last->next) < 0)
			{
				lstswap(last, last->next);
				swapped = 1;
			}
			if (last->next == NULL || last->next == sorted)
			{
				sorted = last;
				continue ;
			}
			last = last->next;
		}
	}
}
