/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/06 17:14:57 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	len_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**env_dup(char **newenv, char **env, int *i)
{
	while (env[*i])
	{
		newenv[*i] = ft_strdup(env[*i]);
		(*i)++;
	}
	return (newenv);
}

char	**ft_sort(char **newenv, char *tmp, int *i)
{
	int	j;

	j = *i + 1;
	while (newenv[*i + 1])
	{
		j = *i + 1;
		while (newenv[j])
		{
			if (ft_strcmp(newenv[*i], newenv[j]) > 0)
			{
				tmp = newenv[j];
				newenv[j] = newenv[*i];
				newenv[*i] = tmp;
			}
			j++;
		}
		(*i)++;
	}
	newenv[*i - 1] = newenv[*i];
	newenv[*i] = NULL;
	return (newenv);
}

char	**sort_env(char **env)
{
	int		i;
	char	*tmp;
	char	**newenv;

	tmp = NULL;
	i = len_env(env);
	newenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	newenv = env_dup(newenv, env, &i);
	newenv[i] = NULL;
	i = 0;
	newenv = ft_sort(newenv, tmp, &i);
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

void	export_builtin(char **arg, char ***env)
{
	(void)arg;
	(void)env;
}
