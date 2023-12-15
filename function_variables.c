/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:05:45 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/14 20:46:35 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	**operators_set(void)
{
	static const char	*operators[] = (const char *[]){"<", "<<", ">", ">>", \
		"|", "||", "&&", "(", ")", NULL};

	return (operators);
}

t_stream	*m_stream(void)
{
	static t_stream	mini_stream = {.input = -1, .output = -1, .next_input = -1, .previous_output = -1, .saved_stdin_fd = -1, .saved_stdout_fd = -1};

	if (mini_stream.saved_stdin_fd == -1)
		mini_stream.saved_stdin_fd = dup(0);
	if (mini_stream.saved_stdout_fd == -1)
		mini_stream.saved_stdout_fd = dup(1);
	return (&mini_stream);
}

int	*m_exit_code(void)
{
	static int	exit_code = 0;
	
	return (&exit_code);
}

int	*m_last_exit_code(void)
{
	static int	exit_code = 0;
	
	return (&exit_code);
}