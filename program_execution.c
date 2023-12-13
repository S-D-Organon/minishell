/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:21:30 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/13 16:53:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**path_split(char **envp)
{
	char	*path_value;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path_value = envp[i] + ft_strlen("PATH=");
	return (ft_split(path_value, ':'));
}

void	command_not_found(char *cmd_name)
{
	*m_exit_code() = 127;
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("Command not found", 2);
}

char	*path_search(char *cmd_name, char **path)
{
	char	*path_name;
	int		i;

	if (path == NULL)
		return (NULL);
	if (is_executable(cmd_name))
		return (ft_strdup(cmd_name));
	i = 0;
	while (path[i] != NULL)
	{
		path_name = str_merge(ft_strjoin(path[i], "/"), ft_strdup(cmd_name));
		if (path_name == NULL)
			break ;
		if (is_executable(path_name))
			return (path_name);
		free(path_name);
		i++;
	}
	command_not_found(cmd_name);
	array_free(path, 2);
	return (NULL);
}

int	program_routine(char *path_name, char **cmd, char **envp)
{
	if (m_stream_use())
		return (0);
	if (cmd[0] != NULL && execve(path_name, cmd, envp) == -1)
		perror("execve");
	return (errno);
}

int	program_execution(char **cmd, char **envp)
{
	pid_t	pid;
	char	*path_name;
	int		wait_status;

	if (cmd[0] != NULL)
	{
		path_name = path_search(cmd[0], path_split(envp));
		if (path_name == NULL)
			return (0);
	}
	pid = fork();
	if (pid < 0)
		return (0);
	else if (pid == 0)
		exit(program_routine(path_name, cmd, envp));
	if (m_stream()->input != -1 && close(m_stream()->input))
		return (0);
	if (m_stream()->previous_output != -1 && close(m_stream()->previous_output))
		return (0);
	waitpid(pid, &wait_status, 0);
	if (WIFEXITED(wait_status))
		return (0);
	free(path_name);
	return (1);
}