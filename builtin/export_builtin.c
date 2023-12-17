/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:41:27 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 23:57:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../minishell.h>

int    lentillequall(char *str)
{
    int    i;

    i = 0;
    while (str[i] && str[i] != '=')
    {
        i++;
    }
    if (str[i] == '\0')
        return (-1);
    return (i);
}

int    ft_lentab(char **tab)
{
    int    i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void    freetab(char **tab)
{
    int    i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int	check_syntax(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (1);
	if ((arg[0] < 'a' || arg[0] > 'z') && (arg[0] < 'A' || arg[0] > 'Z'))
	{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(arg, 1);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
	}
	while (arg[i])
	{
		if ((arg[i] < 'a' || arg[i] > 'z') && (arg[i] < 'A' || arg[i] > 'Z') && arg[i] < '0' && arg[i] > '9')
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(arg, 1);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	checkarg(char **env, char *arg)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], arg, ft_strlen(arg)) == 0 || ft_strncmp(env[i], arg, ft_strlen(env[i])) == 0 || ft_strncmp(env[i], arg, lentillequall(arg)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char **ft_add_env(char **env, char *arg)
{
	int	len;
	char **tmp;
	int	i;

	len = ft_lentab(env);
	i = -1;
	tmp = malloc(sizeof(char *) * (len + 2));
	if (!tmp)
		return (NULL);
	while (env[++i])
	{
		tmp[i] = ft_strdup(env[i]);
		if (!tmp[i])
			return (NULL);
	}
	tmp[i] = ft_strdup(arg);
	if (!tmp[i])
		return (NULL);
	tmp[i + 1] = NULL;
	freetab(env);
	return (tmp);
}

char **modify_env(char **env, char *arg)
{
	int	i;

	i = - 1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], arg, lentillequall(arg)) == 0 && ft_chr(arg, '=') == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(arg);
		}
	}
	return (env);
}

char	**cpytab(char **sort)
{
	int		i;
	char	**new;

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

void	printexport(char ***env)
{
	int		i;
	char	**sort;

	i = 0;
	//finalexport(env);
	sort = cpytab((*env));
	sort = sort_env(sort);
	while (sort[i])
	{
		printf("declare x : %s\n", sort[i]);
		i++;
	}
	free(sort);
}

int	export_builtin(char **arg, char ***env)
{
	int	i;

	i = -1;
	if (!arg[0])
		printexport(env);
	else if (arg[0] && arg[0][0] == '-')
	{
		ft_putstr_fd("export don't take option\n", 2);
		return (0);
	}
	while (arg[++i])
	{
		if (check_syntax(arg[i]) == 0 && checkarg((*env), arg[i]) == 0)
			(*env) = ft_add_env((*env), arg[i]);
		else if (check_syntax(arg[i]) == 0 && checkarg(*env, arg[i]) == 1)
			(*env) = modify_env((*env), arg[i]);
	}
	return (0);
}
