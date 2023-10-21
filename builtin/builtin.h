/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:57:14 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/21 18:44:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//cd builtin
int	cd_builtin(char *path);

//echo builtin
int	echo_builtin(char **strings);

//pwd builtin
int	pwd_builtin(void);

//export builtin
int	export_builtin(char **var);

//unset builtin
int	unset_builtin(char **var);

//env builtin
int	env_builtin(char *envp[]);

//exit
int	exit_builtin(int n);

#endif
