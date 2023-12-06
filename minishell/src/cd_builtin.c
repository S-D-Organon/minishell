/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:49:42 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/30 16:19:51 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_findoldpwd(char **env, int i)
{
	while (env[i])
	{
		if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
			break;
		i++;
	}
	return (i);
}

int	ft_findpwd(char **env, int i)
{
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
			break;
		i++;
	}
	return (i);
}

char	*ft_getcwd(char *env, char *pwd, char *choose)
{
	if (getcwd(pwd, PATH_MAX) != NULL)
		env = ft_strjoin(choose, pwd);
	return (env);
}

void	cd_builtin(char **arg, char **env)
{
	int	i;
	char pwd[PATH_MAX];

	i = 0;
	if (arg[0] == NULL)
	{
		i = ft_findoldpwd(env, i);
		free(env[i]);
		env[i] = ft_getcwd(env[i], pwd, "OLDPWD=");
		printf("%s\n", env[i]);
		i = ft_findpwd(env, i);
		free(env[i]);
		chdir(getenv("HOME"));
		env[i] = ft_getcwd(env[i], pwd, "PWD=");
		printf("%s\n", env[i]);
	}
	else if (arg[1] != NULL)
		printf("cd : too many arguments\n");
	else
	{
		i = ft_findpwd(env, i);
		free(env[i]);
		env[i] = ft_getcwd(env[i], pwd, "PWD=");
		if (chdir(arg[0]) != 0)
			printf("cd : no such file or directory : %s\n", arg[0]);
		else
		{
			i = ft_findoldpwd(env, i);
			free(env[i]);
			env[i] = ft_strjoin("OLDPWD=", env[ft_findpwd(env, i)] + 4);
			printf("%s\n", env[i]);
			i = ft_findpwd(env, i);
			free(env[i]);
			env[i] = ft_getcwd(env[i], pwd, "PWD=");
			printf("%s\n", env[i]);
		}
	}
}
