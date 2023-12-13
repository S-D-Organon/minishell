/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:36:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/11 09:59:26 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
int	env_builtin(char **arg, char ***env)
{
	int	i;

	i = 0;
	if (arg[0] != NULL)
	{
		ft_printf("no args needed\n");
		return (errno);
	}
	while ((*env)[i])
	{
		ft_printf("%s\n", (*env)[i]);
		i++;
	}
	return (errno);
}
