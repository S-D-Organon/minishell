/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:15:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/19 12:55:35 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//a token is either:
//	-a word: sequence of character which does not include unquoted metacharacter
//	-an operator: sequence of character which must include at least one metacharacter
//
//metacharacters: space, tab, newline, '|', '&', ';', '(', ')', '<', '>'
int	is_token(char c)
{
	static char	quote;

	if (c == ''')
	{
		if (quote == '\0')
			quote = ''';
		else if (quote == ''')
			quote = '\0';
	}
	else if (c == '"')
	{
		if (quote == '\0')
			quote = '"';
		else if (quote == '"')
			quote = '\0';
	}
	else if (c == '\0')
		quote = '\0';
	if (quote != '\0')
		return (1);
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
