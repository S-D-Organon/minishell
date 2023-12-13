/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:18:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/13 05:57:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*next_redirection_operator(t_list *command)
{
	while (command != NULL && !is_redirection_operator(command->content))
		command = command->next;
	return (command);
}

int	command_len(t_list *command)
{
	int	len;

	len = 0;
	while (command != NULL)
	{
		if (!is_redirection_operator(command->content))
			len++;
		else
			command = command->next;
		command = command->next;
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
			i++;
		}
		else
			command = command->next;
		command = command->next;
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