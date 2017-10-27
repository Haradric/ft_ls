/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:16:49 by mbraslav          #+#    #+#             */
/*   Updated: 2017/04/07 18:16:53 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_mtime(time_t mtime, char **m, char **d, char **t)
{
	char	*mtime_str;
	char	**mtime_str_splitted;

	mtime_str_splitted = NULL;
	mtime_str = ctime(&mtime);
	mtime_str_splitted = ft_strsplit(mtime_str, ' ');
	*m = ft_strdup(mtime_str_splitted[1]);
	*d = ft_strdup(mtime_str_splitted[2]);
	if (time(NULL) < mtime || mtime < time(NULL) - 15778800)
		*t = ft_strsub(mtime_str_splitted[4], 0, 4);
	else
		*t = ft_strsub(mtime_str_splitted[3], 0, 5);
	freestrarr(mtime_str_splitted);
}

char	*get_username(uid_t uid)
{
	struct passwd	*entry;

	entry = getpwuid(uid);
	return (ft_strdup(entry->pw_name));
}

char	*get_groupname(gid_t gid)
{
	struct group	*entry;

	entry = getgrgid(gid);
	return (ft_strdup(entry->gr_name));
}
