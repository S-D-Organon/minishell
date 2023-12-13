/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/13 17:21:09 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	firstcharalpha(char *arg)
{
	if (arg == NULL)
		return (2);
	if ((arg[0] >= 'a' && arg[0] <= 'z') || (arg[0] >= 'A' && arg[0] <= 'Z') || arg[0] == '-')
		return (0);
	return (1);
}

int	ft_tiret(char **arg)
{
	if (arg[0] == NULL)
		return (2);
	if (ft_strcmp(arg[0], "-") == 0 && arg[1] == NULL)
		return (0);
	return (1);
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

int	*iskeywithout(char **arg)
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
		if (ft_chr(arg[i], '=') > 1 && arg[i][ft_chr(arg[i], '=')] != '\0')
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

void	inittab(char ***tab, char **arg, int *index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (arg[i])
	{
		if (isinintpointer(i, index, findindex(arg)) == 0 && arg[i][0] != '=')
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
				free((*env)[i]);
				(*env)[i] = ft_strjoin(str[k][0], "=");
				tmp = ft_strdup((*env)[i]);
				free((*env)[i]);
				(*env)[i] = ft_strjoin(tmp, str[k][1]);
				free(tmp);
			}
			k++;
		}
		i++;
	}
}

void	printexport(char ***env, char **tab)
{
	char **sort;
	int	i;
	int	j;

	i = 0;
	j = 0;
	sort = malloc(sizeof(char *) * (ft_lentab((*env)) + ft_lentab(tab) + 1));
	while ((*env)[i])
	{
		sort[i] = ft_strdup((*env)[i]);
		i++;
	}
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

void	export_builtin(char **arg, char ***env)
{
	int *index;
	char **tab;
	static int len;

	len += ft_lentab(arg) - findindex(arg);
	index = iskeywithout(arg);
	tab = malloc(sizeof(char *) * (len + 1));
	inittab(&tab, arg, index);
	checktab(&tab);
	changeenv(env, arg, index);
	checkenvarg(env, arg, index);
	printexport(env, tab);
}
