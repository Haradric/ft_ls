/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:16:02 by mbraslav          #+#    #+#             */
/*   Updated: 2017/04/06 18:16:05 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion(t_list *info, t_opt *conf)
{
	t_info	*entry;

	while (info)
	{
		entry = info->content;
		if ((entry->st_mode & S_IFMT) == S_IFDIR && \
			ft_strcmp(entry->name, ".") && ft_strcmp(entry->name, ".."))
		{
			ft_printf("\n%s:\n", entry->path);
			ls_dir(entry, conf);
		}
		info = info->next;
	}
}
