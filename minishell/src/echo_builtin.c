/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:22:51 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/23 14:58:20 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	echo_builtin(t_data *data)
{
	int	i;

	i = 1;
	if (ft_strcmp("echo", data->arg[0]) == 0)
	{
		if (data->arg[1] != NULL && ft_strcmp("-n", data->arg[1]) == 0)
		{
			i = 2;
			while (i < data->sizedata)
			{
				ft_printf("%s", data->arg[i]);
				ft_printf(" ");
				i++;
			}
			ft_printf("%s", data->arg[i]);
		}
		else if (data->sizedata > 0)
		{
			while (i < data->sizedata)
			{
				ft_printf("%s", data->arg[i]);
				ft_printf(" ");
				i++;
			}
			ft_printf("%s", data->arg[i]);
			ft_printf("\n");
		}
	}
}
