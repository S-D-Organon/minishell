/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:50:54 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 15:35:04 by lseiberr         ###   ########.fr       */
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
	int		sizeenv;
	int		sizedata;
	char	**arg;
	char	**env;
	char	*oldpwd;
}	t_data;

//utils.c
int		ft_strcmp(char *s1, char *s2);
int		ft_chr(char *str, char c);
char	*ft_getcwd(char *env, char *pwd, char *choose);
char	**changeenvdir(char **env, int i, char *pwd);
void	ft_else(char **arg, char ***env, int i, char *pwd);
//pwd_builtin.c
int		pwd_builtin(char **arg, char ***env);
//echo_builtin.c
int		echo_builtin(char **arg, char ***env);
//cd_builtin.c
int		cd_builtin(char **arg, char ***env);
int		ft_findoldpwd(char **env);
int		ft_findpwd(char **env);
//env_builtin.c
int		env_builtin(char **arg, char ***env);
//exit_builtin.c
void	exit_builtin(char **arg, char ***env);
//export_builtin.c
int		export_builtin(char **arg, char ***env);
int		changeenv(char ***env, char **arg, int *index);
char	**strplusenv(char *arg, char **env);
int		changeexport(char ***env, char **tab);
//utils_export
int		lentillequall(char *str);
int		checkcmp(char *str, char *str2);
void	freetab(char **tab);
int		*iskeywithout(char **env, char **arg);
int		ft_lentab(char **tab);
//utils_export_second
int		firstcharalpha(char *arg);
int		ft_isalnumequal(char *str);
int		ft_isalphatillequal(char *str);
int		findindex(char **arg);
int		ft_printerror(char **arg, char ***env);
//utils_export_third
int		checkenvarg(char ***env, char **arg, int *index);
int		isinintpointer(int i, int *index, int size);
int		inittab(char ***tab, char **env, char **arg, int *index);
int		countempty(char **tab);
char	**ft_emptytab(char **tab);
//utils_export_forth
int		checktab(char ***tab);
char	***splitarg(char **arg, int *index);
char	***splitenv(char **env);
int		checksubstr(char *s1, char *s2);
void	freetab3d(char ***str);
//utils_export_fifth
int		ft_strcmpplus(char *s1, char *s2);
int		ft_check_env(char **env, char *arg);
char	**cpytab(char **sort);
int		lentillequallvt(char *str);
int		ft_strcmpenv(char *s1, char *s2);
//utils_export_sixth
void	printexport(char ***env);
int		ft_checkinput(char **arg);
void	ft_equal(char **arg, char ***env);
void	finalexport(char ***env);
char	**ft_cpyenv(char ***env, char **sort, int *i);
//utils_export_seventh
char	**strplusenv(char *arg, char **env);
int		ft_argnull(char **tmp, char **str, char **arg);
int		verrifmalloctab(char **env, char *str);
int		verifmalloc(char *str, char *tmp);
int		verifenv(char ***env, char **sort);
//unset
int		unset_builtin(char **arg, char ***env);
char	**ft_realloc(char **env, int change);
//reverse_split
char	*ft_reverse_split(char **tab);
//sort_env
char	**sort_env(char **env);

#endif
