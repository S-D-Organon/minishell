/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:59:52 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/13 20:59:04 by lseiberr         ###   ########.fr       */
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
	newenv = env_dup(newenv, env);
	newenv = ft_sort(newenv);
	return (newenv);
} 
