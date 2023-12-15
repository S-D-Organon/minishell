/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/15 16:59:33 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ifchangeenv(char ***env, char ****str, char **tmp, int *i)
{
	(*env)[i[0]] = ft_strjoin((*str)[i[1]][0], "=");
	if (!(*env)[i[0]])
	{
		freetab3d((*str));
		return (1);
	}
	(*tmp) = ft_strdup((*env)[i[0]]);
	if (!(*tmp))
	{
		freetab3d((*str));
		free((*env)[i[0]]);
		return (1);
	}
	(*env)[i[0]] = ft_strjoin((*tmp), (*str)[i[1]][1]);
	if (!(*env)[i[0]])
	{
		free((*tmp));
		freetab3d((*str));
		return (1);
	}
	free((*tmp));
	(*tmp) = NULL;
	return (0);
}

int	changeenv(char ***env, char **arg, int *index)
{
	char	***str;
	int		i[2];
	char	*tmp;

	i[0] = -1;
	str = splitarg(arg, index);
	if (!str)
		return (1);
	while ((*env)[++i[0]])
	{
		i[1] = -1;
		while (str[++i[1]])
		{
			if (checksubstr(str[i[1]][0], (*env)[i[0]]) == 0)
			{
				if (ifchangeenv(env, &str, &tmp, i) == 1)
					return (1);
			}
		}
	}
	freetab3d(str);
	return (0);
}

char	**ft_cpyenv(char ***env, char **sort, int *i)
{
	while ((*env)[++*i])
	{
		sort[*i] = ft_strdup((*env)[*i]);
		if (!sort[*i])
			return (NULL);
	}
	sort[*i] = NULL;
	return (sort);
}

int	verifenv(char ***env, char **sort)
{
	if (!(*env))
	{
		freetab(sort);
		return (1);
	}
	return (0);
}

int	changeexport(char ***env, char **tab)
{
	char	**sort;
	int		i;
	int		j;

	i = -1;
	j = -1;
	sort = malloc(sizeof(char *) * (ft_lentab((*env)) + ft_lentab(tab) + 1));
	if (!sort)
		return (1);
	sort = ft_cpyenv(env, sort, &i);
	if (!sort)
		return (1);
	while (tab[++j])
	{
		sort[i] = ft_strdup(tab[j]);
		if (!sort[i])
			return (1);
		i++;
	}
	sort[i] = NULL;
	(*env) = cpytab(sort);
	if (verifenv(env, sort) == 1)
		return (1);
	freetab(sort);
	return (0);
}

int	export_builtin(char **arg, char ***env)
{
	int		*index;
	char	**tab;
	int		len;

	if (ft_checkinput(arg) == 1)
	{
		printf("not a valid arg\n");
		return (0);
	}
	if (arg[0] == NULL)
	{
		printexport(env);
		return (0);
	}
	ft_equal(arg, env);
	len = ft_lentab(arg) - findindex(arg);
	index = iskeywithout((*env), arg);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		free(index);
	if (inittab(&tab, (*env), arg, index) == 1 || checktab(&tab) == 1 || \
	changeenv(env, arg, index) == 1 \
	|| checkenvarg(env, arg, index) == 1 || changeexport(env, tab) == 1)
		free(index);
	if (errno == ENOMEM)
		return (1);
	free(index);
	return (0);
}
