/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:59:52 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/14 02:44:18 by lseiberr         ###   ########.fr       */
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

char	**env_dup(char **newenv, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		newenv[i] = ft_strdup(env[i]);
		if (!newenv[i])
			return (NULL);
		i++;
	}
	newenv[i] = NULL;
	return (newenv);
}

char	**ft_sort(char **newenv)
{
	int	i;
	int	j;
	char *tmp;

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
	return (newenv);
}

char	**sort_env(char **env)
{
	char	**newenv;

	newenv = malloc(sizeof(char *) * (len_env(env) + 1));
	if (!newenv)
		return (NULL);
	newenv = env_dup(newenv, env);
	if (!newenv)
		return (NULL);
	newenv = ft_sort(newenv);
	return (newenv);
}
