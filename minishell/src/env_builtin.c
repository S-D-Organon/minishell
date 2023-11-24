/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:36:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/24 14:15:44 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env_builtin(t_data *data)
{
	int	i;

	i = 0;
	if (data->arg[0] == NULL || ft_strcmp(data->arg[0], "env"))
		return ;
	if (data->arg[1] != NULL)
	{
		ft_printf("no args needed\n");
		return ;
	}
	while (data->env[i])
	{
		ft_printf("%s\n", data->env[i]);
		i++;
	}
}
