/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:15:40 by mbraslav          #+#    #+#             */
/*   Updated: 2017/03/04 18:15:41 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*read_params(int argc, char **argv)
{
	t_list	*list;
	char	*content;

	list = NULL;
	while (argc != 1 && argv[argc - 1][0] != '-')
	{
		content = argv[argc-- - 1];
		ft_lstpush(&list, content, ft_strlen(content) + 1);
	}
	if (!list)
		list = ft_lstnew(".", ft_strlen("."));
	return (list);
}
