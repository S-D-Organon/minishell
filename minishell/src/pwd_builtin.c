/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:45:56 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/27 13:12:45 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd_builtin(char **arg, char **env)
{
	char pwd[PATH_MAX];
	(void)env;
	
	if (arg[0] != NULL)
	{
		printf("pwd: too many arguments\n");
		return ;
	}
	if (getcwd(pwd, PATH_MAX) != NULL)
		printf("%s\n", pwd);
}
/*
int	main(int ac, char **ag, char **env)
{
	pwd_builtin(ag + 1, env);
}
*/
