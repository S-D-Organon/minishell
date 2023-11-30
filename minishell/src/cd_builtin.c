/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:49:42 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/27 15:49:32 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cd_builtin(char **arg, char **env)
{
	int	i;
	char pwd[PATH_MAX];

	i = 0;
	if (arg[0] == NULL)
	{
		while (env[i])
		{
			if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
				break;
			i++;
		}
		free(env[i]);
		if (getcwd(pwd, PATH_MAX) != NULL)
		env[i] = ft_strjoin("OLDPWD=", pwd);
		printf("%s\n", env[i]);
		i = 0;
		while (env[i])
		{
			if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
				break;
			i++;
		}
		free(env[i]);
		chdir(getenv("HOME"));
		if (getcwd(pwd, PATH_MAX) != NULL)
		env[i] = ft_strjoin("PWD=", pwd);
		printf("%s\n", env[i]);
	}
	else if (arg[1] != NULL)
		printf("cd : string not in pwd %s\n", arg[0]);
	else
	{
		while (env[i])
		{
			if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
				break;
			i++;
		}
		free(env[i]);
		if (getcwd(pwd, PATH_MAX) != NULL)
			env[i] = ft_strjoin("PWD=", pwd);
		if (chdir(arg[0]) != 0)
			printf("cd : no such file or directory : %s\n", arg[0]);
		else
			while (env[i])
		{
			if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
				break;
			i++;
		}
		free(env[i]);
		env[i] = ft_strjoin("OLDPWD=", getenv("PWD"));
		printf("%s\n", env[i]);
		i = 0;
		while (env[i])
		{
			if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
				break;
			i++;
		}
		free(env[i]);
		if (getcwd(pwd, PATH_MAX) != NULL)
		env[i] = ft_strjoin("PWD=", pwd);
		printf("%s\n", env[i]);
	}
}
