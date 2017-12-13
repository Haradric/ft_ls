/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:15:29 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/03 19:15:30 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/xattr.h>

typedef struct		s_opt
{
	char			rb;
	char			a;
	char			l;
	char			r;
	char			t;
	char			sb;
}					t_opt;

typedef struct		s_info
{
	char			*name;
	char			*path;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	blkcnt_t		st_blocks;
	dev_t			st_rdev;
	struct timespec	st_mtimespec;
}					t_info;

typedef struct		s_pinfo
{
	char			*name;
	char			*mode;
	int				links;
	char			*user;
	char			*group;
	int				major;
	int				minor;
	long long		size;
	char			*mtimem;
	char			*mtimed;
	char			*mtimet;
}					t_pinfo;

typedef struct		s_table
{
	size_t			links;
	size_t			user;
	size_t			group;
	size_t			major;
	size_t			minor;
	size_t			size;
}					t_table;

void				ls(t_list *path, t_opt *conf, int multidir);
void				sort(t_list **list, t_opt *flags);
int					cmp_name(void *a, void *b);
int					cmp_time(void *a, void *b);

void				ls_files(t_list *file, t_opt *conf);
void				ls_files_long(t_list *info);
void				ls_files_short(t_list *info);
void				ls_dir(t_info *directory, t_opt *conf);
void				ls_dirs(t_list *dir, t_opt *conf, int multidir);

t_info				*get_info(char *name, char *path, t_opt *flags, int type);
t_list				*get_printable_info(t_list *entry);
char				*get_mode(t_info *info);
void				set_mtime(time_t mtime, char **m, char **d, char **t);
char				*get_username(uid_t uid);
char				*get_groupname(gid_t gid);

void				freeinfo(void *content);
void				freepinfo(void *content);
void				freestrarr(char **arr);

t_opt				*read_options(int argc, char **argv);
t_list				*read_params(int argc, char **argv);

void				calc_table(t_list *list, t_table *table);

void				expand_str(char **s1, const char *s2, int pos);

void				error(const char *s, int stop);
int					is_dir(char *path, t_opt *conf);
long long			get_total(t_list *list);
void				recursion(t_list *info, t_opt *conf);

int					cmp_name(void *a, void *b);
int					cmp_time(void *a, void *b);
int					cmp_size(void *a, void *b);

void				lstsort(t_list **list, int (*cmp)(void *a, void *b));
void				lstrsort(t_list **list, int (*cmp)(void *a, void *b));

#endif
