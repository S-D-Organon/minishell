/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:55:16 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/10 03:23:28 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
int	builtin_routine(char **cmd, char ***envp_ptr)
{
	int	exit_status;

	exit_status = 0;
	if (m_stream_use())
		return (errno);
	if (!ft_strncmp(cmd[0], "echo", -1))
		exit_status = echo_builtin(cmd, envp_ptr);
	if (!ft_strncmp(cmd[0], "cd", -1))
		exit_status = cd_builtin(cmd, envp_ptr);
	if (!ft_strncmp(cmd[0], "pwd", -1))
		exit_status = pwd_builtin(cmd, envp_ptr);
	if (!ft_strncmp(cmd[0], "export", -1))
		exit_status = export_builtin(cmd, envp_ptr);
	if (!ft_strncmp(cmd[0], "unset", -1))
		exit_status = unset_builtin(cmd, envp_ptr);
	if (!ft_strncmp(cmd[0], "env", -1))
		exit_status = env_builtin(cmd, envp_ptr);
	if (!ft_strncmp(cmd[0], "exit", -1))
		exit_status = exit_builtin(cmd, envp_ptr);
	return (exit_status);
}

int	builtin_execution(char **cmd, char ***envp_ptr, int builtin_create_subshell)
{
	pid_t	pid;
	int		wait_status;

	if (builtin_create_subshell)
		pid = fork();
	if (builtin_create_subshell && pid < 0)
		return (errno);
	if (builtin_create_subshell && pid == 0)
		exit(builtin_routine(cmd, envp_ptr));
	if (builtin_create_subshell && pid > 0)
	{
		waitpid(pid, &wait_status, 0);
		if (WIFEXITED(wait_status))
			return (WEXITSTATUS(wait_status));
		return (errno);
	}
	if (!builtin_create_subshell)
		return (builtin_routine);
}
*/