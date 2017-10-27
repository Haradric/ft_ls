/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:17:00 by mbraslav          #+#    #+#             */
/*   Updated: 2017/04/07 18:17:01 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_file_type(mode_t mode)
{
	int		type;

	type = (mode & S_IFMT);
	if (type == S_IFDIR)
		return ('d');
	else if (type == S_IFCHR)
		return ('c');
	else if (type == S_IFBLK)
		return ('b');
	else if (type == S_IFREG)
		return ('-');
	else if (type == S_IFLNK)
		return ('l');
	else if (type == S_IFSOCK)
		return ('s');
	else
		return (0);
}

static char	*get_permissions(mode_t mode)
{
	char	*permission;
	int		i;
	int		mask;

	permission = ft_strdup("rwxrwxrwx");
	i = 0;
	mask = 1 << 8;
	while (i < 9)
	{
		if (!(mode & mask))
			permission[i] = '-';
		i++;
		mask >>= 1;
	}
	if (mode & S_ISUID)
		permission[2] = 's';
	if (mode & S_ISGID)
		permission[5] = 's';
	if (mode & S_ISVTX)
		permission[8] = 't';
	return (permission);
}

static int	get_xattr(char *path)
{
	if (listxattr(path, NULL, 0, 0) > 0)
		return (1);
	else
		return (0);
}

char		*get_mode(t_info *info)
{
	char	*ret;
	char	*permissions;

	ret = ft_strnew(11);
	ret[0] = get_file_type(info->st_mode);
	permissions = get_permissions(info->st_mode);
	ft_strcpy(&ret[1], permissions);
	ret[10] = (get_xattr(info->path)) ? '@' : ' ';
	free(permissions);
	return (ret);
}
