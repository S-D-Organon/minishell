/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/07 00:05:21 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	export_builtin(char **arg, char ***env)
{
	(void)arg;

	printf("%s\n", ft_reverse_split(sort_env((*env))));
}
