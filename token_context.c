/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_context.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:32:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/23 17:19:50 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char *c)
{
	if (*c == '|' || *c == '&' || *c == ';' || *c == '(' || *c == ')' || *c == '<' || *c == '>')
		return (1);
	return (0);
}

int	word_sequence(char *c, char *previous_c)
{
	static char	*next_quote;
	int		res;

	if (c == NULL)
	{
		next_quote = NULL;
		return (0);
	}
	if (previous_c != NULL && is_operator(previous_c))
		return (0);
	res = 0;
	if (next_quote == NULL && (*c == '\'' || *c == '"'))
	{
		next_quote = c + sizeof(char);
		while (*next_quote && *next_quote != *c)
			next_quote += sizeof(char);
		next_quote -= (*next_quote == '\0') * sizeof(char);
	}
	if (next_quote != NULL)
		res = 1;
	else if (*c != ' ' && *c != '\t' && !is_operator(c))
		res = 1;
	if (c == next_quote)
		next_quote = NULL;
	return (res);
}

int	operator_sequence(char *c, char *previous_c)
{
	static char	*last_operator;
	int		res;

	if (c == NULL)
	{
		last_operator = NULL;
		return (0);
	}
	if (previous_c != NULL && !isspace(*previous_c) && !is_operator(previous_c))
		return (0);
	res = 0;
	if (last_operator == NULL && is_operator(c))
	{
		last_operator = c + sizeof(char);
		while (*last_operator && is_operator(last_operator))
			last_operator += sizeof(char);
		last_operator -= sizeof(char);
	}
	if (last_operator != NULL)
		res = 1;
	if (c == last_operator)
		last_operator = NULL;
	return (res);
}

//a token is either:
//	-a word: sequence of character which does not include unquoted metacharacter
//	-an operator: sequence of character which must include at least one unquoted metacharacter and
//	is either a control operator or a redirection operator
//
//metacharacters: space, tab, newline, '|', '&', ';', '(', ')', '<', '>'
int	token_context(char *c)
{
	static char	*previous_c;
	int		res;

	if (c == NULL)
	{
		word_sequence(NULL, NULL);
		operator_sequence(NULL, NULL);
		previous_c = NULL;
		return (0);
	}
	res = 0;
	if (word_sequence(c, previous_c))
		res = 1;
	else if (operator_sequence(c, previous_c))
		res = 1;
	previous_c = c;
	return (res);
}
