/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:17:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/29 23:09:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*pipeline_list_init(char **token)
{
	t_list	*pipeline;
	int	i;

	i = 0;
	while (token[i])
	{
		if (is_control_operator(token[i]))
		{
		}
		else
		{
		}
	}
}

int	parser(char **token)
{
	t_list	*pipeline;

	if (operator_syntax_check(token))
		return (2);
	pipeline = pipeline_list_init(token);
	if (pipeline == NULL)
		return (errno);
	errno = pipeline_list_exec(pipeline);
	ft_lstclear(&pipeline, &command_delete);
	return (errno);
}
