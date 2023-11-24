/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:50:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/24 14:30:58 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <string.h>
# include <limits.h>
# include <curses.h>

typedef struct s_data
{
	int	sizeenv;
	int	sizedata;
	char **arg;
	char **env;
	char *oldpwd;
}	t_data;

//utils.c
int	ft_strcmp(char *s1, char *s2);
//pwd_builtin.c
void	pwd_builtin(t_data *data);
//echo_builtin.c
void	echo_builtin(t_data *data);
//cd_builtin.c
void	cd_builtin(t_data *data);
//env_builtin.c
void	env_builtin(t_data *data);
//exit_builtin.c
void	exit_builtin(t_data *data);

#endif
