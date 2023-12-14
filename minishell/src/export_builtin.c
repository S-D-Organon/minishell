/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/14 01:43:28 by lseiberr         ###   ########.fr       */
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
		if (ft_chr(arg[i], '=') > 1 && arg[i][ft_chr(arg[i], '=')] != '\0' && \
		ft_check_env(env, arg[i]) == 0)
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
	if (!str)
		return (NULL);
	if (arg != NULL)
	{
		tmp = ft_strdup(str);
		if (!tmp)
		{
			free(str);
			return (NULL);
		}
		free(str);
		str = ft_strjoin(tmp, "\n");
		if (!str)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
		tmp = ft_strdup(str);
		if (!tmp)
		{
			free(str);
			return (NULL);
		}
		free(str);
		str = ft_strjoin(tmp, arg);
		if (!str)
		{
			free(str);
			return (NULL);
		}
		free(tmp);
	}
	env = ft_split(str, '\n');
	if (!env)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (env);
}

int	checkenvarg(char ***env, char **arg, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (i < findindex(arg))
	{
		j = 0;
		while ((*env)[j])
		{
			if (checkcmp((*env)[j], arg[index[i]]) == 0)
			{
				break;
			}
			j++;
		}
		if (j == ft_lentab((*env)))
		{
			(*env) = strplusenv(arg[index[i]], (*env));
			if (!(*env))
				return (1);
		}
		i++;
	}
	return (0);
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

int	inittab(char ***tab, char **env, char **arg, int *index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (arg[i])
	{
		if (isinintpointer(i, index, findindex(arg)) == 0 && arg[i][0] != '=' \
		&& ft_check_env(env, arg[i]) == 0)
		{
			(*tab)[k] = ft_strdup(arg[i]);
			if (!(*tab)[k])
				return (1);
			k++;
		}
		i++;
	}
	while (k < findindex(arg))
	{
		(*tab)[k] = NULL;
		k++;
	}
	return (0);
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
	if (!tmp)
		return (NULL);
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "") != 0)
		{
			tmp[j] = ft_strdup(tab[i]);
			if (!tmp[j])
				return (NULL);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	freetab(tab);
	return (tmp);
}

int	checktab(char ***tab)
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
				if (!(*tab)[j])
					return (1);
			}
			j++;
		}
		i++;
	}
	(*tab) = ft_emptytab((*tab));
	if (!(*tab))
		return (1);
	return (0);
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
	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i][0], arg) == 0 || ft_strcmpplus(str[i][0], arg) == 0)
		{
			freetab3d(str);
			return (1);
		}
		i++;
	}
	freetab3d(str);
	return (0);
}

int	changeenv(char ***env, char **arg, int *index)
{
	char ***str;
	int	i;
	int k;
	char *tmp;

	i = 0;
	str = splitarg(arg, index);
	if (!str)
		return (1);
	while ((*env)[i])
	{
		k = 0;
		while (str[k])
		{
			if (checksubstr(str[k][0], (*env)[i]) == 0)
			{
				(*env)[i] = ft_strjoin(str[k][0], "=");
				if (!(*env)[i])
					return (1);
				tmp = ft_strdup((*env)[i]);
				if (!tmp)
					return (1);
				(*env)[i] = ft_strjoin(tmp, str[k][1]);
				if (!(*env)[i])
					return (1);
				free(tmp);
				tmp = NULL;
			}
			k++;
		}
		i++;
	}
	freetab3d(str);
	return (0);
}

char **cpytab(char **sort)
{
	int	i;
	char **new;

	new = malloc(sizeof(char *) * (ft_lentab(sort) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (sort[i])
	{
		new[i] = ft_strdup(sort[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	changeexport(char ***env, char **tab)
{
	char **sort;
	int	i;
	int	j;

	i = -1;
	j = 0;
	sort = malloc(sizeof(char *) * (ft_lentab((*env)) + ft_lentab(tab) + 1));
	if (!sort)
		return (1);
	while ((*env)[++i])
	{
		sort[i] = ft_strdup((*env)[i]);
		if (!sort[i])
			return (1);
	}
	while (tab[j])
	{
		sort[i] = ft_strdup(tab[j]);
		if (!sort[i])
			return (1);
		i++;
		j++;
	}
	sort[i] = NULL;
	(*env) = cpytab(sort);
	if (!(*env))
	{
		free(sort);
		return (1);
	}
	free(sort);
	return (0);
}

int	lentillequallvt(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		i++;
	}
	return (i);
}

int	ft_strcmpenv(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (lentillequallvt(s1) != lentillequallvt(s2))
		return (1);
	while (i < lentillequallvt(s1))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	finalexport(char ***env)
{
	int	i;
	int	j;

	i = 0;
	while ((*env)[i])
	{
		j = i + 1;
		while ((*env)[j])
		{
			if (ft_strcmpenv((*env)[i], (*env)[j]) == 0)
			{
				if (ft_chr((*env)[i], '=') == 0)
					(*env) = ft_realloc((*env), i);
				else
					(*env) = ft_realloc((*env), j);
			}
			j++;
		}
		i++;
	}
}

void	printexport(char ***env)
{
	int	i;
	char **sort;

	i = 0;
	finalexport(env);
	sort = cpytab((*env));
	sort = sort_env(sort);
	while (sort[i])
	{
		printf("declare x : %s\n", sort[i]);
		i++;
	}
	free(sort);
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

void	ft_equal(char **arg, char ***env)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (arg[++i])
	{
		if (ft_chr(arg[i], '=') > 0)
		{
			j = -1;
			while ((*env)[++j])
			{
				k = 0;
				while ((*env)[j] && arg[i] && k < (int)ft_strlen(arg[i]))
				{
					if ((*env)[j][k] != arg[i][k])
						break;
					k++;
				}
				if (k == (int)ft_strlen(arg[i]) || k == (int)ft_strlen((*env)[j]))
					(*env)[j] = arg[i];
			}
		}
	}
}

int	export_builtin(char **arg, char ***env)
{
	int *index;
	char **tab;
	int len;

	if (ft_checkinput(arg) == 1)
	{
		printf("not a valid arg\n");
		return (0);
	}
	if (arg[0] == NULL)
	{
		printexport(env);
		return (0);
	}
	ft_equal(arg, env);
	len = ft_lentab(arg) - findindex(arg);
	index = iskeywithout((*env), arg);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
	{
		free(index);
		return (1);
	}
	if (inittab(&tab, (*env), arg, index) == 1 || checktab(&tab) == 1 || \
	changeenv(env, arg, index) == 1 \
	|| checkenvarg(env, arg, index) == 1 || changeexport(env, tab) == 1)
	{
		free(index);
		return (1);
	}
	free(index);
	return (0);
}
