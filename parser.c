/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:17:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/02 20:37:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_check(t_list *token)
{
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

int	parser(t_list *token)
{
	//t_list	*pipeline;

	if (syntax_check(token))
		return (2);
	/*
	pipeline = pipeline_list_init(token);
	if (pipeline == NULL)
		return (errno);
	errno = pipeline_list_exec(pipeline);
	ft_lstclear(&pipeline, &command_delete);
	*/
	return (errno);
}
