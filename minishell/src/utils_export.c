/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:41 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/15 15:33:12 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	lentillequall(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	checkcmp(char *str, char *str2)
{
	int	i;
	int len1;
	int len2;

	i = 0;
	len1 = lentillequall(str);
	len2 = lentillequall(str2);
	if (len1 != len2)
		return (-1);
	while (i < len1)
	{
		if (str[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*iskeywithout(char **env, char **arg)
{
	int	*index;
	int	i;
	int	j;

	j = findindex(arg);
	index = malloc(sizeof(int) * j);
	if (!index)
		return (NULL);
	i = 0;
	j = 0;
	while (arg[i])
	{
		if (ft_chr(arg[i], '=') > 1 && arg[i][ft_chr(arg[i], '=')] != '\0' && \
		ft_check_env(env, arg[i]) == 0)
		{
			index[j] = i;
			j++;
		}
		i++;
	}
	return (index);
}
