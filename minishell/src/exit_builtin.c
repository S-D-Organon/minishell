/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:22:00 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/24 14:34:06 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_builtin(t_data *data)
{
	if (data->arg[0] == NULL || ft_strcmp(data->arg[0], "exit") != 0)
		return ;
	exit(0);
}
