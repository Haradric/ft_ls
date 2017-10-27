/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:34:46 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:34:47 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls(t_list *path, t_opt *conf, int multidir)
{
	t_list	*last;
	t_list	*files;
	t_list	*dirs;

	last = path;
	files = NULL;
	dirs = NULL;
	while (last)
	{
		if (is_dir(last->content, conf) == -1)
			error(last->content, 0);
		else if (is_dir(last->content, conf))
			ft_lstpush(&dirs, last->content, last->content_size);
		else
			ft_lstpush(&files, last->content, last->content_size);
		last = last->next;
	}
	if (files)
		ls_files(files, conf);
	if (files && dirs)
		write(1, "\n", 1);
	if (dirs)
		ls_dirs(dirs, conf, multidir);
	ft_lstfree(&files, free);
	ft_lstfree(&dirs, free);
}
