/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:33:59 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/30 15:11:07 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strequal(char *env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkexist(char *arg, char *env)
{
	int	i;

	i = 0;
	if (ft_strequal(arg) == 1)
		return (0);
	while (arg[i] == env[i] && arg[i] && env[i])
		i++;
	if (!arg[i] && !env[i])
		return (1);
	if (!arg[i] && env[i] == '=')
		return (1);
	return (0);
}

char	**ft_realloc(char **env, int change)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	while (env[i])
		i++;
	temp = malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (i != change)
		{
			temp[j] = env[i];
			j++;
		}
		else
			free(env[i]);
		i++;
	}
	temp[j] = NULL;
	free(env);
	return (temp);
}


void	unset_builtin(char **arg, char **env)
{
	int		i;
	int		j;

	i = 1;
	if (arg[1][0] == '-')
	{
		ft_putstr_fd("minishell: unset does not take any option.\n", 1);
		return ;
	}
	while (arg[i])
	{
		j = 0;
		while (env[j])
		{
			if (ft_checkexist(arg[i], env[j]) == 1)
			{
				*env = ft_realloc(env, j);
				break ;
			}
			j++;
		}
		i++;
	}
}
