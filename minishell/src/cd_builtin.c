/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:49:42 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/07 00:06:07 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_findoldpwd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' \
		&& env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
			break ;
		i++;
	}
	return (i);
}

int	ft_findpwd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
			break ;
		i++;
	}
	return (i);
}

char	**cd_home(char **env, int i, char *pwd)
{
	i = ft_findoldpwd(env);
	free(env[i]);
	env[i] = ft_getcwd(env[i], pwd, "OLDPWD=");
	i = ft_findpwd(env);
	free(env[i]);
	chdir(getenv("HOME"));
	env[i] = ft_getcwd(env[i], pwd, "PWD=");
	return (env);
}

char	**changeenvdir(char **env, int i, char *pwd)
{
	i = ft_findoldpwd(env);
	free(env[i]);
	env[i] = ft_strjoin("OLDPWD=", env[ft_findpwd(env)] + 4);
	i = ft_findpwd(env);
	free(env[i]);
	env[i] = ft_getcwd(env[i], pwd, "PWD=");
	return (env);
}

void	cd_builtin(char **arg, char ***env)
{
	int		i;
	char	pwd[PATH_MAX];

	i = 0;
	if (arg[0] == NULL || ft_strcmp(arg[0], "~") == 0)
		(*env) = cd_home((*env), i, pwd);
	else if (arg[1] != NULL)
		printf("cd : too many arguments\n");
	else
	{
		if (ft_strcmp(arg[0], "-") == 0)
			chdir((*env)[ft_findoldpwd((*env))] + 7);
		else
		{
			if (chdir(arg[0]) != 0)
				printf("cd : no such file or directory : %s\n", arg[0]);
			else
				changeenvdir((*env), i, pwd);
		}
	}
}
