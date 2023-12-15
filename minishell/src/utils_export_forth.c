/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_forth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:35 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/15 15:41:37 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	checktab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*tab)[i + 1])
	{
		j = i + 1;
		while ((*tab)[j])
		{
			if (ft_strcmp((*tab)[i], (*tab)[j]) == 0)
			{
				free((*tab)[j]);
				(*tab)[j] = ft_strdup("");
				if (!(*tab)[j])
					return (1);
			}
			j++;
		}
		i++;
	}
	(*tab) = ft_emptytab((*tab));
	if (!(*tab))
		return (1);
	return (0);
}

char	***splitarg(char **arg, int *index)
{
	char ***split;
	int	i;
	int	k;

	split = malloc(sizeof(char **) * (findindex(arg) + 1));
	i = 0;
	k = 0;
	while (arg[i])
	{
		if (isinintpointer(i, index, findindex(arg)) == 1)
		{
			split[k] = ft_split(arg[i], '=');
			k++;
		}
		i++;
	}
	split[k] = NULL;
	return (split);
}

char	***splitenv(char **env)
{
	char ***split;
	int	i;

	split = malloc(sizeof(char **) * (ft_lentab(env) + 1));
	i = 0;
	while (env[i])
	{
		split[i] = ft_split(env[i], '=');
		i++;
	}
	split[i] = NULL;
	return (split);
}

int	checksubstr(char *s1, char *s2)
{
	int i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	if ((int)ft_strlen(s2) < len)
		return (1);
	while (len > 0 && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
		len--;
	}
	if (s2[i] && s2[i] == '=')
		return (0);
	return (1);
}

void	freetab3d(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		freetab(str[i]);
		i++;
	}
	free(str);
}
