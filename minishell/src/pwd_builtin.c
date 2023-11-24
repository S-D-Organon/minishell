/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:45:56 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/24 14:05:42 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd_builtin(t_data *data)
{
	char pwd[PATH_MAX];

	if (data->arg[0] != NULL && ft_strcmp(data->arg[0], "pwd") == 0)
	{
		if (data->arg[1] != NULL)
		{
			ft_printf("pwd: too many arguments\n");
			return ;
		}
		if (getcwd(pwd, PATH_MAX) != NULL)
			ft_printf("%s\n", pwd);
	}
}
