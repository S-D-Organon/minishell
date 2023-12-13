/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:50:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/11 10:03:23 by lseiberr         ###   ########.fr       */
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
# include <signal.h>

typedef struct s_data
{
	int	sizeenv;
	int	sizedata;
	char **arg;
	char **env;
	char *oldpwd;
}	t_data;

//utils.c
int		ft_strcmp(char *s1, char *s2);
int		ft_chr(char *str, char c);
char	*ft_getcwd(char *env, char *pwd, char *choose);
//pwd_builtin.c
int	pwd_builtin(char **arg, char ***env);
//echo_builtin.c
int	echo_builtin(char **arg, char ***env);
//cd_builtin.c
int	cd_builtin(char **arg, char ***env);
//env_builtin.c
int	env_builtin(char **arg, char ***env);
//exit_builtin.c
void	exit_builtin(char **arg, char ***env);
//export_builtin.c
void	export_builtin(char **arg, char ***env);
//unset
int	unset_builtin(char **arg, char ***env);
//reverse_split
char	*ft_reverse_split(char **tab);
//sort_env
char	**sort_env(char **env);
#endif
