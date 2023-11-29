/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:27:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/29 22:15:12 by gdornic          ###   ########.fr       */
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

const char	**operators_set(void)
{
	static const char	*operators[] = (const char *[]){"<", "<<", ">", ">>", \
		"|", "||", "&&", "(", ")", NULL};

	return (operators);
}