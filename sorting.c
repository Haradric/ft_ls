/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:39:28 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:39:29 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp_name(void *a, void *b)
{
	t_list	*l1;
	t_list	*l2;
	t_info	*e1;
	t_info	*e2;

	l1 = (t_list *)a;
	l2 = (t_list *)b;
	e1 = l1->content;
	e2 = l2->content;
	return (ft_strcmp(e1->name, e2->name));
}

int		cmp_time(void *a, void *b)
{
	t_list	*l1;
	t_list	*l2;
	t_info	*e1;
	t_info	*e2;

	l1 = (t_list *)a;
	l2 = (t_list *)b;
	e1 = l1->content;
	e2 = l2->content;
	if (e1->st_mtimespec.tv_sec == e2->st_mtimespec.tv_sec)
	{
		if (e1->st_mtimespec.tv_nsec == e2->st_mtimespec.tv_nsec)
			return (cmp_name(a, b));
		else if (e1->st_mtimespec.tv_nsec > e2->st_mtimespec.tv_nsec)
			return (-1);
		else
			return (1);
	}
	else if (e1->st_mtimespec.tv_sec > e2->st_mtimespec.tv_sec)
		return (-1);
	else
		return (1);
}

int		cmp_size(void *a, void *b)
{
	t_list	*l1;
	t_list	*l2;
	t_info	*e1;
	t_info	*e2;

	l1 = (t_list *)a;
	l2 = (t_list *)b;
	e1 = l1->content;
	e2 = l2->content;
	if (e1->st_size == e2->st_size)
		return (cmp_name(a, b));
	else if (e1->st_size > e2->st_size)
		return (-1);
	else
		return (1);
}

void	sort(t_list **list, t_opt *flags)
{
	if (flags->t == 1)
	{
		if (flags->r == 1)
			ft_lstrsort(list, cmp_time);
		else
			ft_lstsort(list, cmp_time);
	}
	else if (flags->sb == 1)
	{
		if (flags->r == 1)
			ft_lstrsort(list, cmp_size);
		else
			ft_lstsort(list, cmp_size);
	}
	else
	{
		if (flags->r == 1)
			ft_lstrsort(list, cmp_name);
		else
			ft_lstsort(list, cmp_name);
	}
}
