/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_seventh.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:10:07 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/15 16:10:08 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	verifmalloc(char *str, char *tmp)
{
	if (!tmp)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	verrifmalloctab(char **env, char *str)
{
	if (!env)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	ft_argnull(char **tmp, char **str, char **arg)
{
	(*tmp) = ft_strdup((*str));
	if (verifmalloc((*str), (*tmp)) == 1)
		return (1);
	free((*str));
	(*str) = ft_strjoin((*tmp), "\n");
	if (verifmalloc((*tmp), (*str)) == 1)
		return (1);
	free((*tmp));
	(*tmp) = ft_strdup((*str));
	if (verifmalloc((*str), (*tmp)) == 1)
		return (1);
	free((*str));
	(*str) = ft_strjoin((*tmp), (*arg));
	if (verifmalloc((*tmp), (*str)) == 1)
		return (1);
	free((*tmp));
	return (0);
}

char	**strplusenv(char *arg, char **env)
{
	char	*tmp;
	char	*str;

	str = ft_reverse_split(env);
	if (!str)
		return (NULL);
	if (arg != NULL)
		ft_argnull(&tmp, &str, &arg);
	env = ft_split(str, '\n');
	if (verrifmalloctab(env, str) == 1)
		return (NULL);
	free(str);
	return (env);
}
