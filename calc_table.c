/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:34:28 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:34:36 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	calc_table2(t_pinfo *entry, t_table *table)
{
	size_t	len;

	if (entry->major == -1)
		len = 0;
	else
		len = ft_nbrlen(entry->major);
	if (table->major < len)
		table->major = len;
	if (entry->minor == -1)
		len = 0;
	else
		len = ft_nbrlen(entry->minor);
	if (table->minor < len)
		table->minor = len;
}

void		calc_table(t_list *list, t_table *table)
{
	t_pinfo	*entry;
	size_t	len;

	ft_memset(table, 0, sizeof(t_table));
	while (list)
	{
		entry = (t_pinfo *)list->content;
		len = ft_nbrlen(entry->links);
		if (table->links < len)
			table->links = len;
		len = ft_strlen(entry->user);
		if (table->user < len)
			table->user = len;
		len = ft_strlen(entry->group);
		if (table->group < len)
			table->group = len;
		len = ft_nbrlen(entry->size);
		if (table->size < len)
			table->size = len;
		calc_table2(entry, table);
		list = list->next;
	}
}
