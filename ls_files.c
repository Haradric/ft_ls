/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:36:32 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:36:33 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_line(t_table *table, t_pinfo *entry)
{
	if (table->major == 0)
		ft_printf("%11s %*d %-*s  %-*s  %*lld %s %2s %5s %s\n", entry->mode, \
		table->links, entry->links, table->user, entry->user, \
		table->group, entry->group, table->size, entry->size, \
		entry->mtimem, entry->mtimed, entry->mtimet, entry->name);
	else
	{
		if (entry->mode[0] == 'c' || entry->mode[0] == 'b')
			ft_printf("%11s %*d %-*s  %-*s   %*d, %*d %s %2s %5s %s\n", \
			entry->mode, table->links, entry->links, table->user, entry->user, \
			table->group, entry->group, table->major, entry->major, \
			table->minor, entry->minor, entry->mtimem, entry->mtimed, \
			entry->mtimet, entry->name);
		else
			ft_printf("%11s %*d %-*s  %-*s %*s %*lld %s %2s %5s %s\n", \
			entry->mode, table->links, entry->links, table->user, entry->user, \
			table->group, entry->group, table->major + 2, " ", \
			table->size, entry->size, entry->mtimem, entry->mtimed, \
			entry->mtimet, entry->name);
	}
}

void		ls_files_long(t_list *info)
{
	t_list	*last;
	t_pinfo	*entry;
	t_list	*pinfo;
	t_table	table;

	last = info;
	pinfo = get_printable_info(info);
	calc_table(pinfo, &table);
	last = pinfo;
	while (last)
	{
		entry = (t_pinfo *)last->content;
		print_line(&table, entry);
		last = last->next;
	}
	ft_lstfree(&pinfo, freepinfo);
}

void		ls_files_short(t_list *files)
{
	t_list	*last;
	t_info	*info;

	last = files;
	while (last)
	{
		info = (t_info *)last->content;
		ft_printf("%s\n", info->name);
		last = last->next;
	}
}

void		ls_files(t_list *file, t_opt *conf)
{
	t_list		*info;
	t_list		*last;
	t_info		*entry;

	info = NULL;
	last = file;
	while (last)
	{
		entry = get_info(last->content, "", conf, 1);
		ft_lstpush(&info, entry, sizeof(t_info));
		free(entry);
		last = last->next;
	}
	sort(&info, conf);
	if (conf->l == 1)
		ls_files_long(info);
	else
		ls_files_short(info);
	ft_lstfree(&info, freeinfo);
}
