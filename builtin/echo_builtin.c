/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:22:51 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 22:30:59 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			return (0);
	}
	printf("\n");
	return (0);
}
