/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:36:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 15:20:48 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	checkafterequal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	env_builtin(char **arg, char ***env)
{
	int	i;

	i = 0;
	if (arg[0] != NULL)
	{
		ft_printf("no args needed\n");
		//*m_exit_code() = 1;
		return (0);
	}
	while ((*env)[i])
	{
		if (ft_chr((*env)[i], '=') > 0 && checkafterequal((*env)[i]) == 0)
			ft_printf("%s\n", (*env)[i]);
		i++;
	}
	return (0);
}
