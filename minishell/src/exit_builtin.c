/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:22:00 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 16:32:15 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_builtin(char **arg, char ***env)
{
	(void)env;
	if (arg[1] != NULL)
	{
		ft_putstr_fd("too many arguments\n", 2);
		return ;
	}
	exit(0);
}
