/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:41:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/10 06:51:04 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*next_list_operator(t_list *token)
{
	while (token != NULL && !is_list_operator(token->content))
		token = token->next;
	return (token);
}

t_list	*skip_group(t_list *token)
{
	int	left_bracket_count;

	token = token->next;
	left_bracket_count = 0;
	while (token != NULL && is_left_bracket(token->content))
	{
		left_bracket_count++;
		token = token->next;
	}
	while (left_bracket_count > 0)
	{
		if (is_right_bracket(token->content))
			left_bracket_count--;
		token = token->next;
	}
	return (next_list_operator(token));
}

t_list	*next_pipeline(t_list *token)
{
	t_list	*pipeline;
	t_list	*new;
	char	*content;

	pipeline = NULL;
	while (is_bracket(token->content) || is_list_operator(token->content))
		token = token->next;
	while (token != NULL && !is_list_operator(token->content) && !is_bracket(token->content))
	{
		content = ft_strdup(token->content);
		if (content == NULL)
			break ;
		new = ft_lstnew(content);
		if (new == NULL)
		{
			free(content);
			break ;
		}
		ft_lstadd_back(&pipeline, new);
		token = token->next;
	}
	if (errno == ENOMEM)
		ft_lstclear(&pipeline, &free);
	return (pipeline);
}

//step 1: make the next pipeline from the token list
//step 2: execute the pipeline
//step 3: search the next list operator, if NULL is found stop the recursion
//step 4: evaluate exit status, potentially skip the next group of pipelines
//step 5: go back to step 1 with a new position in the token list
int	execution(t_list *token, char ***envp_ptr, int exit_status)
{
	t_list	*pipeline;

	pipeline = next_pipeline(token);
	if (pipeline == NULL)
		return (errno);
	exit_status = pipeline_execution(pipeline, envp_ptr, 0);
	ft_lstclear(&pipeline, &free);
	if (exit_status == ENOMEM)
		return (exit_status);
	token = next_list_operator(token);
	if (token == NULL)
		return (exit_status);
	if (is_and(token->content) && exit_status)
		token = skip_group(token);
	else if (is_or(token->content) && !exit_status)
		token = skip_group(token);
	if (token == NULL)
		return (exit_status);
	return (execution(token->next, envp_ptr, exit_status));
}
