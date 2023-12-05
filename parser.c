/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:17:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/05 21:14:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_check(t_list *token)
{
	bracket_count_rule(NULL, NULL);
	if (is_control_operator((char *)token->content))
		return (syntax_error((char *)token->content));
	while (token != NULL)
	{
		if (syntax_rules(token))
			return (1);
		token = token->next;
	}
	return (0);
}

int	parser(t_list *token, char ***envp_ptr)
{
	if (syntax_check(token))
		return (2);
	return (execution(token, envp_ptr, 0));
}
