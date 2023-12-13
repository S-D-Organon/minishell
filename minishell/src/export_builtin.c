/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/13 21:46:37 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	firstcharalpha(char *arg)
{
	if (arg == NULL)
		return (2);
	if ((arg[0] >= 'a' && arg[0] <= 'z') || (arg[0] >= 'A' && arg[0] <= 'Z'))
		return (0);
	return (1);
}

int	ft_isalnumequal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_isalphatillequal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if ((str[i] <= 'a' || str[i] >= 'z') && (str[i] <= 'A' || str[i] >= 'Z'))
			return (1);
		i++;
	}
	return (0);
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

int	*iskeywithout(char **env, char **arg)
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
		if (ft_chr(arg[i], '=') > 1 && arg[i][ft_chr(arg[i], '=')] != '\0' && ft_check_env(env, arg[i]) == 1)
		{
			index[j] = i;
			j++;
		}
		i++;
	}
	return (index);
}

int	lentillequall(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		i++;
	}
	if (str[i] == '\0')
		return(-1);
	return (i);
}

int	checkcmp(char *str, char *str2)
{
	int	i;
	int len1;
	int len2;

	i = 0;
	len1 = lentillequall(str);
	len2 = lentillequall(str2);
	if (len1 != len2)
		return (-1);
	while (i < len1)
	{
		if (str[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**strplusenv(char *arg, char **env)
{
	char	*tmp;
	char	*str;


	str = ft_reverse_split(env);
	if (arg != NULL)
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, arg);
		free(tmp);
	}
	env = ft_split(str, '\n');
	free(str);
	//printf("%d\n", ft_lentab(env));
	//printf("%s\n", env[25]);
	return (env);
}

void	checkenvarg(char ***env, char **arg, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (i < findindex(arg))
	{
		j = 0;
		while ((*env)[j])
		{
			//printf("%s, %s\n", env[j], arg[index[i]]);
			if (checkcmp((*env)[j], arg[index[i]]) == 0)
			{
			//	printf("stop\n");
				break;
			}
			j++;
		}
		if (j == ft_lentab((*env)))
		{
			(*env) = strplusenv(arg[index[i]], (*env));
			//printf("coucou");
		}
		i++;
	}
}

int	isinintpointer(int i, int *index, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		if (i == index[k])
			return (1);
		k++;
	}
	return (0);
}
/*
void	tabstepone(char ***tab, int *k)
{
	char **tmp;

	tmp = malloc(sizeof(char *) * (ft_lentab((*tab)) + 1));
	while ()
}
*/
void	inittab(char ***tab, char **env, char **arg, int *index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	//if (!(*tab))
	//	tabstepone(tab, &k);
	while (arg[i])
	{
		if (isinintpointer(i, index, findindex(arg)) == 0 && arg[i][0] != '=' && ft_check_env(env, arg[i]) == 1)
		{
			(*tab)[k] = ft_strdup(arg[i]);
			k++;
		}
		i++;
	}
	while (k < findindex(arg))
	{
		(*tab)[k] = NULL;
		k++;
	}
}

int	countempty(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "") == 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_emptytab(char **tab)
{
	char **tmp;
	int	j;
	int	i;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char *) * (ft_lentab(tab) - countempty(tab) + 1));
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "") != 0)
		{
			tmp[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	freetab(tab);
	return (tmp);
}

void	checktab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*tab)[i + 1])
	{
		j = i + 1;
		while ((*tab)[j])
		{
			if (ft_strcmp((*tab)[i], (*tab)[j]) == 0)
			{
				free((*tab)[j]);
				(*tab)[j] = ft_strdup("");
			}
			j++;
		}
		i++;
	}
	(*tab) = ft_emptytab((*tab));
}

char	***splitarg(char **arg, int *index)
{
	char ***split;
	int	i;
	int	k;

	split = malloc(sizeof(char **) * (findindex(arg) + 1));
	i = 0;
	k = 0;
	while (arg[i])
	{
		if (isinintpointer(i, index, findindex(arg)) == 1)
		{
			split[k] = ft_split(arg[i], '=');
			k++;
		}
		i++;
	}
	split[k] = NULL;
	return (split);
}

char	***splitenv(char **env)
{
	char ***split;
	int	i;

	split = malloc(sizeof(char **) * (ft_lentab(env) + 1));
	i = 0;
	while (env[i])
	{
		split[i] = ft_split(env[i], '=');
		i++;
	}
	split[i] = NULL;
	return (split);
}

int	checksubstr(char *s1, char *s2)
{
	int i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	if ((int)ft_strlen(s2) < len)
		return (1);
	while (len > 0 && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
		len--;
	}
	if (s2[i] && s2[i] == '=')
		return (0);
	return (1);
}

void	freetab3d(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		freetab(str[i]);
		i++;
	}
	free(str);
}

int	ft_strcmpplus(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2 [i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '=' || s2[i] == '=')
		return (0);
	return (1);
}

int	ft_check_env(char **env, char *arg)
{
	char ***str;
	int	i;

	str = splitenv(env);
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i][0], arg) == 0 || ft_strcmpplus(str[i][0], arg) == 0)
		{
			freetab3d(str);
			return (0);
		}
		i++;
	}
	freetab3d(str);
	return (1);
}

void	changeenv(char ***env, char **arg, int *index)
{
	char ***str;
	int	i;
	int k;
	char *tmp;

	i = 0;
	str = splitarg(arg, index);
	while ((*env)[i])
	{
		k = 0;
		while (str[k])
		{
			if (checksubstr(str[k][0], (*env)[i]) == 0)
			{
				(*env)[i] = ft_strjoin(str[k][0], "=");
				tmp = ft_strdup((*env)[i]);
				(*env)[i] = ft_strjoin(tmp, str[k][1]);
				free(tmp);
				tmp = NULL;
			}
			k++;
		}
		i++;
	}
	freetab3d(str);
}

void	printexport(char ***env, char **tab)
{
	char **sort;
	int	i;
	int	j;

	i = -1;
	j = 0;
	sort = malloc(sizeof(char *) * (ft_lentab((*env)) + ft_lentab(tab) + 1));
	while ((*env)[++i])
		sort[i] = ft_strdup((*env)[i]);
	while (tab[j])
	{
		sort[i] = ft_strdup(tab[j]);
		i++;
		j++;
	}
	sort[i] = NULL;
	sort = sort_env(sort);
	i = 0;
	while (sort[i])
	{
		printf("%s\n", sort[i]);
		i++;
	}
}

int	ft_checkinput(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalnumequal(arg[i]) == 1 || firstcharalpha(arg[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	export_builtin(char **arg, char ***env)
{
	int *index;
	static char **tab;
	static int len;

	if (ft_checkinput(arg) == 1)
	{
		printf("not a valid arg\n");
		return ;
	}
	len += ft_lentab(arg) - findindex(arg);
	printf("%d\n", len);
	index = iskeywithout((*env), arg);
	tab = malloc(sizeof(char *) * (len + 1));
	inittab(&tab, (*env), arg, index);
	checktab(&tab);
	changeenv(env, arg, index);
	checkenvarg(env, arg, index);
	//printexport(env, tab);
	free(index);
}
