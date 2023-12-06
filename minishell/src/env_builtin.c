/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:36:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/30 16:39:56 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env_builtin(char **arg, char ***env)
{
	int	i;

	i = 0;
	if (arg[0] == NULL || ft_strcmp(arg[0], "env") != 0)
		return ;
	if (arg[1] != NULL)
	{
		ft_printf("no args needed\n");
		return ;
	}
	while ((*env)[i])
	{
		ft_printf("%s\n", (*env)[i]);
		i++;
	}
}
