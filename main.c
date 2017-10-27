/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:56:59 by mbraslav          #+#    #+#             */
/*   Updated: 2017/04/12 17:04:33 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt	*config;
	t_list	*arg;
	int		multidir;

	config = read_options(argc, argv);
	arg = read_params(argc, argv);
	multidir = (arg->next != NULL) ? 1 : 0;
	ls(arg, config, multidir);
	ft_lstfree(&arg, free);
	return (0);
}
