/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:22:51 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/11 09:59:10 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	echo_builtin(char **arg, char ***env)
{
	int	i;

	i = 0;
	(void)env;
	if (arg[0] != NULL)
	{
		if (strcmp(arg[0], "-n") == 0)
			i++;
		while (arg[i + 1])
		{
			printf("%s", arg[i]);
			printf(" ");
			i++;
		}
		printf("%s", arg[i]);
		if (ft_strcmp(arg[0], "-n") == 0)
			return (errno);
	}
	printf("\n");
	return (errno);
}
