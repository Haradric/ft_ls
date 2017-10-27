/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:34:58 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/31 18:34:59 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freeinfo(void *content)
{
	t_info	*entry;

	entry = (t_info *)content;
	free(entry->name);
	free(entry->path);
	free(entry);
}

void	freepinfo(void *content)
{
	t_pinfo	*entry;

	entry = (t_pinfo *)content;
	free(entry->name);
	free(entry->mode);
	free(entry->user);
	free(entry->group);
	free(entry->mtimem);
	free(entry->mtimed);
	free(entry->mtimet);
	free(entry);
}

void	freestrarr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}
