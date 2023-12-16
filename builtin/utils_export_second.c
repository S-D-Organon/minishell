/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_second.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:34:07 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 17:44:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		if ((str[i] <= 'a' || str[i] >= 'z') && \
		(str[i] <= 'A' || str[i] >= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	findindex(char **arg)
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

int	ft_printerror(char **arg, char ***env)
{
	if (ft_checkinput(arg) == 1)
	{
		ft_putstr_fd("not a valid arg\n", 2);
		//*m_exit_code() = 1;
		return (1);
	}
	if (arg[0] == NULL)
	{
		printexport(env);
		return (1);
	}
	return (0);
}
