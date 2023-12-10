/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:44:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/10 22:52:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	m_stream_set(void)
{
	m_stream()->input = -1;
	m_stream()->output = -1;
	m_stream()->next_input = -1;
	m_stream()->previous_output = -1;
}

t_list	*next_expanded_command(t_list *pipeline, char **envp)
{
	t_list	*command;
	t_list	*new;
	char	*content;

	command = NULL;
	while (pipeline != NULL && !is_pipe(pipeline->content))
	{
		content = content_expand(pipeline->content, envp);
		if (content == NULL)
			break ;
		new = ft_lstnew(content);
		if (new == NULL)
		{
			free(content);
			break ;
		}
		ft_lstadd_back(&command, new);
		pipeline = pipeline->next;
	}
	if (errno == ENOMEM)
		ft_lstclear(&command, &free);
	return (command);
}

t_list	*next_pipe(t_list *pipeline)
{
	while (pipeline != NULL && !is_pipe(pipeline->content))
		pipeline = pipeline->next;
	return (pipeline);
}

int	pipe_set(int last)
{
	static int	pipe_fd[2] = {-1, -1};

	m_stream()->input = pipe_fd[0];
	m_stream()->previous_output = pipe_fd[1];
	if (last)
	{
		m_stream()->output = m_stream()->saved_stdout_fd;
		m_stream()->next_input = -1;
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
		return (0);
	}
	if (pipe(pipe_fd))
		return (errno);
	m_stream()->output = pipe_fd[1];
	m_stream()->next_input = pipe_fd[0];
	return (0);
}

int	pipeline_routine(t_list *pipeline, char ***envp_ptr, int exit_status, int builtin_create_subshell)
{
	t_list	*command;

	command = next_expanded_command(pipeline, *envp_ptr);
	if (command == NULL)
		return (errno);
	if (builtin_create_subshell)
	{
		if (next_pipe(pipeline) == NULL)
		{
			if (pipe_set(1))
				return (0);
		}
		else if (pipe_set(0))
			return (0);
	}
	exit_status = command_execution(command, envp_ptr, exit_status, builtin_create_subshell);
	if (exit_status == ENOMEM)
		return (errno);
	pipeline = next_pipe(pipeline);
	if (pipeline == NULL)
		return (exit_status);
	return (pipeline_routine(pipeline->next, envp_ptr, exit_status, builtin_create_subshell));
}

//dup2 stdin et stdout ici avant pipeline
int	pipeline_execution(t_list *pipeline, char ***envp_ptr, int exit_status)
{
	*m_exit_code() = 0;
	m_stream_set();
	if (dup2(m_stream()->saved_stdin_fd, 0) == -1)
		return (errno);
	if (dup2(m_stream()->saved_stdout_fd, 1) == -1)
		return (errno);
	return (pipeline_routine(pipeline, envp_ptr, exit_status, next_pipe(pipeline) != NULL));
}