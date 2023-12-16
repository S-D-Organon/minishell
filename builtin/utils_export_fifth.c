/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_fifth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:41:40 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 17:44:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmpplus(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2 [i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '=' || s2[i] == '=')
		return (0);
	return (1);
}

int	ft_check_env(char **env, char *arg)
{
	char	***str;
	int		i;

	str = splitenv(env);
	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i][0], arg) == 0 || \
		ft_strcmpplus(str[i][0], arg) == 0)
		{
			freetab3d(str);
			return (1);
		}
		i++;
	}
	freetab3d(str);
	return (0);
}

char	**cpytab(char **sort)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (ft_lentab(sort) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (sort[i])
	{
		new[i] = ft_strdup(sort[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	lentillequallvt(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		i++;
	}
	return (i);
}

int	ft_strcmpenv(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (lentillequallvt(s1) != lentillequallvt(s2))
		return (1);
	while (i < lentillequallvt(s1))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
