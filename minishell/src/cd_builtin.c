/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:49:42 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/24 14:09:21 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *ft_path(t_data *data, char *current_directory)
{
	char *path;

	path = ft_strjoin(current_directory, "/");
	path = ft_strjoin(current_directory, data->arg[data->sizedata]);
	return (path);
}

void ft_while(int i, int j, char *path, char *current_directory)
{
	while (j < i)
	{
		path[j] = current_directory[j];
		j++;
	}
}

int	ft_whilefori(int i, char *current_directory)
{
	while (current_directory[i])
		i++;
	i--;
	return (i);
}

void	cd_builtin(t_data *data)
{
	char	current_directory[PATH_MAX];
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->oldpwd = getcwd(data->oldpwd, PATH_MAX);
	if (data->arg[0] == NULL || ft_strcmp(data->arg[0], "cd") != 0)
		return ;
	if (data->sizedata == 1)
	{
		if (ft_strcmp(data->arg[data->sizedata], "..") == 0 || ft_strcmp(data->arg[data->sizedata], "../") == 0)
		{
			i = ft_whilefori(i, current_directory);
			while (current_directory[i] != '/')
				i--;
			path = malloc(sizeof(char) * (i + 1));
			ft_while(i, j, path, current_directory);
		}
		else
			path = ft_path(data, current_directory);
	}
	else if (data->sizedata == 0)
		path = getenv("HOME");
	else if (data->sizedata > 1)
	{
		ft_printf("cd :too many args\n");
		return ;
	}
	if (chdir(path) == -1)
		ft_printf("%s: not in pwd\n", data->arg[data->sizedata]);
	else
	{
		i = 0;
		while (data->env[i])
		{
			if (data->env[i][0] == 'O' && data->env[i][1] == 'L' && data->env[i][2] == 'D')
			{
				free(data->env[i]);
				data->env[i] = ft_strjoin("OLDPWD=", data->oldpwd);
			}
			if (data->env[i][0] == 'P' && data->env[i][1] == 'W' && data->env[i][2] == 'D')
			{
				free(data->env[i]);
				data->env[i] = ft_strjoin("PWD=", getcwd(path, PATH_MAX));
			}
			i++;
		}
	}
}
