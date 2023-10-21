/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:56:20 by lseiberr          #+#    #+#             */
/*   Updated: 2023/10/21 17:41:02 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	pwd_builtin(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) != NULL)
	{
		printf("%s\n", pwd);
		return (0);
	}
	return (-1);
}
/*
int	main()
{
	pwd_builtin();
}
*/
