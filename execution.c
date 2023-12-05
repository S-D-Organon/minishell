/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:41:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/05 22:18:39 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*next_list_operator(t_list *token)
{
	while (token != NULL && !is_list_operator(token->content))
		token = token->next;
	return (token);
}

t_list	*next_pipeline(t_list *token)
{
	t_list	*pipeline;
	t_list	*new;
	char	*content;

	pipeline = NULL;
	while (is_bracket(token->content))
		token = token->next;
	while (token != NULL && !is_list_operator(token->content) && !is_bracket(token->content))
	{
		content = ft_strdup(token->content);
		if (content == NULL)
			break ;
		new = ft_lstnew(content);
		if (new == NULL)
			break ;
		ft_lstadd_back(&pipeline, new);
		token = token->next;
	}
	if (errno == ENOMEM)
		ft_lstclear(&pipeline, &free);
	return (pipeline);
}

//step 1: make the next pipeline from the token list
//step 2: perform expansion
//step 3: perform redirection
//step 3: execute the pipeline
//step 4: search the next list operator, if NULL is found stop the recursion
//step 5: evaluate exit status, potentially skip the next group of pipelines
//step 6: go back to step 1 with a new position in the token list
int	execution(t_list *token, char ***envp_ptr, int exit_status)
{
	t_list	*pipeline;

	(void)envp_ptr;
	(void)exit_status;
	pipeline = next_pipeline(token);
	if (pipeline == NULL)
		return (errno);
	if (expansion(pipeline, *envp))
		return (errno);
	if (!redirection(pipeline))
		exit_status = pipeline_execution(pipeline, envp);
	token = next_list_operator(token);
	if (token == NULL)
		return (exit_status);
	if (token->content == "&&" && exit_status)
		token = skip_group(token);
	else if (token->content == "||" && !exit_status)
		token = skip_group(token);
	return (execution(token, envp, exit_status));
}
