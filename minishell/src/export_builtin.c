/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/07 20:19:41 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	firstcharalpha(char *arg)
{
	if (arg == NULL)
		return (2);
	if ((arg[0] >= 'a' && arg[0] <= 'z') || (arg[0] >= 'A' && arg[0] <= 'Z') \
	 || arg[0] == '-')
		return (0);
	return (1);
}

int	ft_tiret(char **arg)
{
	if (arg[0] == NULL)
		return (2);
	if (ft_strcmp(arg[0], "-") == 0 && arg[1] == NULL)
		return (0);
	return (1);
}

int findindex(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (ft_chr(arg[i], '=') > 1 && arg[i][ft_chr(arg[i], '=')] != '\0')
			j++;
		i++;
	}
	return (j);
}

int	*iskeywithout(char **arg)
{
	int *index;
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
		if (ft_chr(arg[i], '=') > 1 && arg[i][ft_chr(arg[i], '=')] != '\0')
		{
			index[j] = i;
			j++;
		}
		i++;
	}
	return (index);
}



void	export_builtin(char **arg, char ***env)
{
	(void)env;
	int *index;
	int	i;

	i = 0;
	index = iskeywithout(arg);
	while (i < findindex(arg))
	{
		printf("%d\n", index[i]);
		i++;
	}
	free (index);
}
