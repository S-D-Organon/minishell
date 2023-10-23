/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:06:04 by lseiberr          #+#    #+#             */
/*   Updated: 2023/10/23 15:42:50 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char	**environ;

void	env_builtin(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
/*
int	main(int ac, char **ag, char **env)
{
	char	*tut;

	environ = env;
	tut = getenv("TMPDIR");
	memcpy(tut, "test", 5);
	//printf("%s\n", getenv("TMPDIR"));
	env_builtin();
}
*/
