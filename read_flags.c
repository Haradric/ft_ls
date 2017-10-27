/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:38:31 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/06 18:38:33 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	set_flag(t_opt *conf, char c)
{
	if (c == 'R')
		conf->rb = 1;
	else if (c == 'a')
		conf->a = 1;
	else if (c == 'l')
		conf->l = 1;
	else if (c == 'r')
		conf->r = 1;
	else if (c == 't')
		conf->t = 1;
	else if (c == 'S')
		conf->sb = 1;
	else
		return (0);
	return (1);
}

t_opt		*read_options(int argc, char **argv)
{
	t_opt	*conf;
	int		i;
	int		j;

	if ((conf = (t_opt *)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	ft_memset(conf, 0, sizeof(t_opt));
	i = 0;
	while (++i <= argc - 1 && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][++j])
		{
			if (!set_flag(conf, argv[i][j]))
			{
				ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] \
[file ...]\n", argv[i][j]);
				exit(1);
			}
		}
	}
	return (conf);
}
