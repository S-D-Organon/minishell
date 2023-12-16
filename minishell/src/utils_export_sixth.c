/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_sixth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:46:51 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/15 22:43:41 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	finalexport(char ***env)
{
	int	i;
	int	j;

	i = 0;
	while ((*env)[i])
	{
		j = i + 1;
		while ((*env)[j])
		{
			if (ft_strcmpenv((*env)[i], (*env)[j]) == 0)
			{
				if (ft_chr((*env)[i], '=') == 0)
					(*env) = ft_realloc((*env), i);
				else
					(*env) = ft_realloc((*env), j);
			}
			j++;
		}
		i++;
	}
}

void	printexport(char ***env)
{
	int		i;
	char	**sort;

	i = 0;
	finalexport(env);
	sort = cpytab((*env));
	sort = sort_env(sort);
	while (sort[i])
	{
		printf("declare x : %s\n", sort[i]);
		i++;
	}
	free(sort);
}

int	ft_checkinput(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalnumequal(arg[i]) == 1 || firstcharalpha(arg[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_equal(char **arg, char ***env)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (arg[++i])
	{
		if (ft_chr(arg[i], '=') > 0)
		{
			j = -1;
			while ((*env)[++j])
			{
				k = 0;
				while ((*env)[j] && arg[i] && k < (int)ft_strlen(arg[i]))
				{
					if ((*env)[j][k] != arg[i][k])
						break ;
					k++;
				}
				if (k == (int)ft_strlen(arg[i]) || \
				k == (int)ft_strlen((*env)[j]))
					(*env)[j] = arg[i];
			}
		}
	}
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
