/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:32:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/20 10:58:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//a token is either:
//	-a word: sequence of character which does not include unquoted metacharacter
//	-an operator: sequence of character which must include at least one metacharacter
//
//metacharacters: space, tab, newline, '|', '&', ';', '(', ')', '<', '>'
int	is_token(char *c)
{
	static char	*next_quote;

	if (c == next_quote)
	{
		next_quote = NULL;
		return (1);
	}
	if (next_quote != NULL && c != next_quote)
		return (1);
	if (next_quote == NULL && (*c == '\'' || *c == '"'))
	{
		next_quote = c + sizeof(char);
		while (*next_quote && *next_quote != *c)
			next_quote += sizeof(char);
		if (*next_quote == '\0')
			next_quote -= sizeof(char);
		if (next_quote == c)
			next_quote = NULL;
	}
	if (*c != ' ' && *c != '\t')
		return (1);
	return (0);
}
