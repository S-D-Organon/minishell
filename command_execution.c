/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:18:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/10 22:52:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	m_stream_use(void)
{
	if (m_stream()->next_input != -1 && close(m_stream()->next_input))
		return (errno);
	if (m_stream()->previous_output != -1 && close(m_stream()->previous_output))
		return (errno);
	if (m_stream()->input != -1 && dup2(m_stream()->input, 0) == -1)
		return (errno);
	if (m_stream()->output != -1  && dup2(m_stream()->output, 1) == -1)
		return (errno);
	return (0);
}

t_list	*next_redirection_operator(t_list *command)
{
	while (command != NULL && !is_redirection_operator(command->content))
		command = command->next;
	return (command);
}

int	m_stream_redirect(t_list *command)
{
	command = next_redirection_operator(command);
	while (command != NULL)
	{
		if (!ft_strncmp("<", command->content, -1) && input_redirect(command->next->content))
			return (errno);
		/*
		if (!ft_strncmp("<<", command->content, -1) && here_doc(command->next->content))
			return (errno);
		if (!ft_strncmp(">", command->content, -1) && output_redirect(command->next->content))
			return (errno);
		if (!ft_strncmp(">>", command->content, -1) && output_redirect_append(command->next->content))
			return (errno);
		*/
		command = command->next;
		command = next_redirection_operator(command);
	}
	return (0);
}

int	command_len(t_list *command)
{
	int	len;

	len = 0;
	while (command != NULL)
	{
		if (!is_redirection_operator(command->content))
		{
			len++;
			command = command->next;
		}
		else
			command = command->next->next;
	}
	return (len);
}

char	**execve_command(t_list *command)
{
	char	**execve_command;
	int		len;
	int		i;

	len = command_len(command);
	execve_command = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (command != NULL)
	{
		if (!is_redirection_operator(command->content))
		{
			execve_command[i] = ft_strdup(command->content);
			if (execve_command[i] == NULL)
			{
				free(execve_command);
				return (NULL);
			}
			command = command->next;
			i++;
		}
		else
			command = command->next->next;
	}
	execve_command[i] = NULL;
	return (execve_command);
}

int	command_execution(t_list *command, char ***envp_ptr, int exit_status, int builtin_create_subshell)
{
	char	**cmd;

	exit_status = 0;
	cmd = execve_command(command);
	if (cmd == NULL)
		return (errno);
	if (m_stream_redirect(command))
	{
		array_free(cmd, 2);
		if (errno == ENOMEM)
			return (1);
		return (0);
	}
	if (is_builtin(cmd[0]))
		exit_status = builtin_execution(cmd, envp_ptr, builtin_create_subshell);
	else
		exit_status = program_execution(cmd, *envp_ptr);
	array_free(cmd, 2);
	return (exit_status);
}