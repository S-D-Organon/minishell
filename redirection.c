/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:10:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/11 17:21:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	existence_check(char *file_name)
{
	if (access(file_name, F_OK))
	{
		*m_exit_code() = 1;
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	return (0);
}

int	permission_check(char *file_name, int mode)
{
	if (access(file_name, mode))
	{
		*m_exit_code() = 1;
		ft_putstr_fd(ERROR_PREFIX, 2);
		ft_putstr_fd(file_name, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (1);
	}
	return (0);
}

int	input_redirect(char *file_name)
{
	int	fd;

	if (existence_check(file_name))
		return (errno);
	if (permission_check(file_name, R_OK))
		return (errno);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (errno);
	m_stream()->input = fd;
	return (0);
}

/*
int	here_doc(char *delimiter)
{
}
*/

int	output_redirect(char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, O_CREAT_PERMISSIONS);
	if (fd < 0)
		return (errno);
	m_stream()->output = fd;
	return (0);
}

int	output_redirect_append(char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, O_CREAT_PERMISSIONS);
	if (fd < 0)
		return (errno);
	m_stream()->output = fd;
	return (0);
}