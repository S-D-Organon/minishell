/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:55:50 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/14 03:14:42 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_signalquit(int sig)
{
	(void)sig;
	kill(0, 0);
	if (sig == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", 1);
	else if (sig == SIGINT)
		write(1, "\n", 1);
}

void	ft_signalnewline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
