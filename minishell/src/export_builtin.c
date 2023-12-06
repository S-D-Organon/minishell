/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/06 16:19:20 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char **newenv;

	tmp = NULL;
	while (env[i])
		i++;
	newenv = malloc(sizeof(char *) * (i+ 1));
	i = 0;
	while (env[i])
	{
		newenv[i] = ft_strdup(env[i]);
		i++;
	}
	newenv[i] = NULL;
	i = 0;
	j = i + 1;
	while (newenv[i + 1])
	{
		j = i + 1;
		while (newenv[j])
		{
			if (ft_strcmp(newenv[i], newenv[j]) > 0)
			{
				tmp = newenv[j];
				newenv[j] = newenv[i];
				newenv[i] = tmp;
			}
			j++;
		}
		i++;
	}
	newenv[i - 1] = newenv[i];
	newenv[i] = NULL;
	return (newenv);
}

int	ft_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	export_builtin(t_data *data)
{
	char **newenv;
	char **tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	newenv = sort_env(data);
	if (data->arg[0] == NULL || ft_strcmp(data->arg[0], "export") != 0)
		return ;
	if (data->arg[1] == NULL)
	{
		while (newenv[i])
		{
			ft_printf("declare -x %s\n", newenv[i]);
			i++;
		}
		i = 0;
	}
	else
	{
		i = 0;
		tmp = malloc(sizeof(char *) * (data->sizeenv + 1));
		while (data->env[i])
		{
			tmp[i] = ft_strdup(data->env[i]);
			i++;
		}
		tmp[i] = NULL;
		free(data->env);
		data->env = malloc(sizeof(char *) * (data->sizeenv + data->sizedata + 1));
		i = 0;
		while (tmp[i])
		{
			data->env[i] = tmp[i];
			i++;
		}
		while (data->arg[j])
		{
			data->env[i] = ft_strdup(data->arg[j]);
			data->sizeenv++;
			i++;
			j++;
		}
		data->env[i] = NULL;
	}
}
