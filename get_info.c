/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:40:54 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:40:59 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info			*get_info(char *name, char *path, t_opt *flags, int type)
{
	t_info		*info;
	struct stat	filestat;
	int			statret;

	if ((info = (t_info *)malloc(sizeof(t_info))) == NULL)
		return (NULL);
	ft_memset(info, 0, sizeof(t_info));
	info->name = ft_strdup(name);
	info->path = ft_strjoin(path, name);
	statret = (type == 0) ? stat(info->path, &filestat) : lstat(info->path, \
																&filestat);
	(statret == -1) ? error(info->path, 1) : NULL;
	info->st_mode = filestat.st_mode;
	info->st_mtimespec = filestat.st_mtimespec;
	if (flags->l)
	{
		info->st_nlink = filestat.st_nlink;
		info->st_uid = filestat.st_uid;
		info->st_gid = filestat.st_gid;
		info->st_size = filestat.st_size;
		info->st_blocks = filestat.st_blocks;
		info->st_rdev = filestat.st_rdev;
	}
	return (info);
}

static void		set_majmin(dev_t st_rdev, t_pinfo *pinfo)
{
	pinfo->major = (int)major(st_rdev);
	pinfo->minor = (int)minor(st_rdev);
	pinfo->size = -1;
}

static void		set_size(off_t size, t_pinfo *pinfo)
{
	pinfo->major = -1;
	pinfo->minor = -1;
	pinfo->size = size;
}

static t_pinfo	*get_printable_info_entry(t_info *entry)
{
	t_pinfo	*pinfo;
	char	linkbuf[1024];
	int		linklen;

	if ((pinfo = (t_pinfo *)malloc(sizeof(t_pinfo))) == NULL)
		return (NULL);
	pinfo->name = ft_strdup(entry->name);
	pinfo->mode = get_mode(entry);
	pinfo->links = entry->st_nlink;
	pinfo->user = get_username(entry->st_uid);
	pinfo->group = get_groupname(entry->st_gid);
	if (pinfo->mode[0] == 'c' || pinfo->mode[0] == 'b')
		set_majmin(entry->st_rdev, pinfo);
	else
		set_size(entry->st_size, pinfo);
	set_mtime(entry->st_mtimespec.tv_sec, &pinfo->mtimem, &pinfo->mtimed,\
			&pinfo->mtimet);
	if ((entry->st_mode & S_IFMT) == S_IFLNK)
	{
		linklen = (int)readlink(entry->path, linkbuf, sizeof(linkbuf));
		linkbuf[linklen] = '\0';
		expand_str(&pinfo->name, " -> ", 1);
		expand_str(&pinfo->name, linkbuf, 1);
	}
	return (pinfo);
}

t_list			*get_printable_info(t_list *info)
{
	t_list	*last;
	t_list	*pinfo;
	t_info	*entry_info;
	t_pinfo	*entry_pinfo;

	pinfo = NULL;
	last = info;
	while (last)
	{
		entry_info = (t_info *)last->content;
		entry_pinfo = get_printable_info_entry(entry_info);
		ft_lstpushback(&pinfo, ft_lstnew(entry_pinfo, sizeof(t_pinfo)));
		free(entry_pinfo);
		last = last->next;
	}
	return (pinfo);
}
