/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:27:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/02 20:15:35 by gdornic          ###   ########.fr       */
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
	i = 6;
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
	if (*str == '|')
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