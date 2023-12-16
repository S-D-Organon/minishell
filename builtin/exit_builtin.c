/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:22:00 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 23:05:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_builtin(char **arg, char ***env)
{
	if (arg != NULL && ft_lentab(arg) > 1)
	{
		ft_putstr_fd(ERROR_PREFIX, 2);
		ft_putendl_fd("exit: too many arguments", 2);
		return (0);
	}
	array_free(*env, 2);
	*env = NULL;
	if (arg != NULL && arg[0] != NULL)
		*m_last_exit_code() = ft_atoi(arg[0]);
	return (1);
}
