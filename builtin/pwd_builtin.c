/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:45:56 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 17:44:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd_builtin(char **arg, char ***env)
{
	char	pwd[PATH_MAX];

	(void)env;
	if (arg[0] != NULL)
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		//*m_exit_code() = 1;
		if (errno == ENOMEM)
			return (1);
		return (0);
	}
	if (getcwd(pwd, PATH_MAX) != NULL)
		printf("%s\n", pwd);
	if (errno == ENOMEM)
		return (1);
	return (0);
}
