/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_third.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:37:34 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 17:44:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	checkenvarg(char ***env, char **arg, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (i < findindex(arg))
	{
		j = 0;
		while ((*env)[j])
		{
			if (checkcmp((*env)[j], arg[index[i]]) == 0)
				break ;
			j++;
		}
		if (j == ft_lentab((*env)))
		{
			(*env) = strplusenv(arg[index[i]], (*env));
			if (!(*env))
				return (1);
		}
		i++;
	}
	return (0);
}

int	isinintpointer(int i, int *index, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		if (i == index[k])
			return (1);
		k++;
	}
	return (0);
}

int	inittab(char ***tab, char **env, char **arg, int *index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (arg[i])
	{
		if (isinintpointer(i, index, findindex(arg)) == 0 && arg[i][0] != '=' \
		&& ft_check_env(env, arg[i]) == 0)
		{
			(*tab)[k] = ft_strdup(arg[i]);
			if (!(*tab)[k])
				return (1);
			k++;
		}
		i++;
	}
	while (k < findindex(arg))
	{
		(*tab)[k] = NULL;
		k++;
	}
	return (0);
}

int	countempty(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "") == 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_emptytab(char **tab)
{
	char	**tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char *) * (ft_lentab(tab) - countempty(tab) + 1));
	if (!tmp)
		return (NULL);
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "") != 0)
		{
			tmp[j] = ft_strdup(tab[i]);
			if (!tmp[j])
				return (NULL);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	freetab(tab);
	return (tmp);
}
