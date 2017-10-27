/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:21:23 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/04 21:21:29 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_dir(char *path, t_opt *conf)
{
	struct stat	filestat;

	if (conf->l == 1)
	{
		if (lstat(path, &filestat) == -1)
			return (-1);
	}
	else
	{
		if (stat(path, &filestat) == -1)
			return (-1);
	}
	if ((filestat.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else
		return (0);
}

void		error(const char *s, int stop)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(s);
	if (stop)
		exit(1);
}

long long	get_total(t_list *list)
{
	long long	total;
	t_info		*info;

	total = 0;
	while (list)
	{
		info = (t_info *)list->content;
		total += info->st_blocks;
		list = list->next;
	}
	return (total);
}
