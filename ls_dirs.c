/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:38:16 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:38:16 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_dir2(t_list **info, t_opt *conf)
{
	if (!*info)
		return ;
	sort(info, conf);
	if (conf->l == 1)
		ft_printf("total %lld\n", get_total(*info));
	if (conf->l == 1)
		ls_files_long(*info);
	else
		ls_files_short(*info);
	if (conf->rb == 1)
		recursion(*info, conf);
	ft_lstfreelist(info, freeinfo);
}

void		ls_dir(t_info *directory, t_opt *conf)
{
	DIR				*dir;
	struct dirent	*fdirent;
	t_list			*info;
	t_info			*entry;
	char			*path;

	if ((dir = opendir(directory->path)) == NULL)
	{
		error(ft_strrchr(directory->path, '/') + 1, 0);
		return ;
	}
	info = NULL;
	path = ft_strjoin(directory->path, "/");
	while ((fdirent = readdir(dir)) != NULL)
	{
		if (conf->a == 0 && fdirent->d_name[0] == '.')
			continue ;
		entry = get_info(fdirent->d_name, path, conf, 1);
		ft_lstpushback(&info, ft_lstnew(entry, sizeof(t_info)));
		free(entry);
	}
	ls_dir2(&info, conf);
	if (closedir(dir) == -1)
		error(directory->path, 0);
	free(path);
}

static void	ls_dirs2(t_list **info, t_opt *conf, int multidir)
{
	t_list	*last;
	t_info	*entry;
	int		first;

	last = *info;
	first = 1;
	while (last)
	{
		entry = last->content;
		if (multidir == 1)
			ft_printf("%s%s:\n", (first == 1) ? "" : "\n", entry->path);
		ls_dir(last->content, conf);
		last = last->next;
		first = 0;
	}
}

void		ls_dirs(t_list *dir, t_opt *conf, int multidir)
{
	t_list		*info;
	t_list		*last;
	t_info		*entry;

	info = NULL;
	last = dir;
	while (last)
	{
		entry = get_info(last->content, "", conf, 0);
		ft_lstpushback(&info, ft_lstnew(entry, sizeof(t_info)));
		free(entry);
		last = last->next;
	}
	sort(&info, conf);
	ls_dirs2(&info, conf, multidir);
	ft_lstfreelist(&info, freeinfo);
}
