/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:27:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/10 05:26:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_metacharacter(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '|' \
	|| c == '&' || c == ';' || c == '(' || c == ')' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_operator(char *str)
{
	int			i;

	if (str == NULL)
		return (1);
	i = 0;
	while (operators_set()[i])
	{
		if (ft_strncmp(operators_set()[i], str, ft_strlen(operators_set()[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_redirection_operator(char *str)
{
	int			i;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(operators_set()[i], str, ft_strlen(operators_set()[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_control_operator(char *str)
{
	int			i;

	if (str == NULL)
		return (1);
	i = 4;
	while (i < 7)
	{
		if (ft_strncmp(operators_set()[i], str, ft_strlen(operators_set()[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_list_operator(char *str)
{
	int			i;

	if (str == NULL)
		return (0);
	i = 5;
	while (i < 7)
	{
		if (ft_strncmp(operators_set()[i], str, ft_strlen(operators_set()[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_pipe(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp(str, "|", ft_strlen(str)))
		return (1);
	return (0);
}

int	is_right_bracket(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == ')')
		return (1);
	return (0);
}

int	is_left_bracket(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '(')
		return (1);
	return (0);
}

int	is_word(char *str)
{
	if (str == NULL)
		return (0);
	if (is_metacharacter(*str))
		return (0);
	return (1);
}

int	is_bracket(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '(' || *str == ')')
		return (1);
	return (0);
}

int	is_and(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp("&&", str, -1))
		return (1);
	return (0);
}

int	is_or(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp("||", str, -1))
		return (1);
	return (0);
}

int	is_left_arrow(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp("<", str, -1))
		return (1);
	return (0);
}

int	is_right_arrow(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp(">", str, -1))
		return (1);
	return (0);
}

int	is_double_left_arrow(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp("<<", str, -1))
		return (1);
	return (0);
}

int	is_double_right_arrow(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_strncmp(">>", str, -1))
		return (1);
	return (0);
}

int	is_executable(char *path_name)
{
	if (access(path_name, F_OK))
		return (0);
	if (access(path_name, X_OK))
	{
		*m_exit_code() = 126;
		ft_putstr_fd(ERROR_PREFIX, 2);
		ft_putstr_fd(path_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	return (1);
}

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (0);
	if (!ft_strncmp(cmd, "echo", -1))
		return (1);
	if (!ft_strncmp(cmd, "cd", -1))
		return (1);
	if (!ft_strncmp(cmd, "pwd", -1))
		return (1);
	if (!ft_strncmp(cmd, "export", -1))
		return (1);
	if (!ft_strncmp(cmd, "unset", -1))
		return (1);
	if (!ft_strncmp(cmd, "env", -1))
		return (1);
	if (!ft_strncmp(cmd, "exit", -1))
		return (1);
	return (0);
}