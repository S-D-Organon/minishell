/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:45:56 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 15:03:33 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	pwd_builtin(char **arg, char ***env)
{
	char	pwd[PATH_MAX];

	(void)env;
	if (arg[0] != NULL)
	{
		printf("pwd: too many arguments\n");
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
