/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/16 23:14:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//step 1: read input
//step 2: lexical analysis(convert input into tokens)
//step 3: syntaxic analysis(check token positioning)
//step 4: interpret tokens into list of pipeline(s)
//step 5: execute pipeline(s)
int	minishell_loop(char ***envp_ptr)
{
	char	*input;
	t_list	*token;

	input = readline(PROMPT);
	token = NULL;
	while (input != NULL)
	{
		add_history(input);
		errno = 0;
		token = tokenizer(input);
		free(input);
		if (errno == ENOMEM)
			break ;
		*m_exit_code() = 0;
		if (token != NULL && parser(token, envp_ptr))
			break ;
		*m_last_exit_code() = *m_exit_code();
		ft_lstclear(&token, &free);
		if (errno == ENOMEM)
			break ;
		input = readline(PROMPT);
	}
	ft_lstclear(&token, &free);
	rl_clear_history();
	if (errno == ENOMEM)
		*m_last_exit_code() = 1;
	return (*m_last_exit_code());
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**envp_cpy;
	int		exit_code;

	(void)argv;
	signal(SIGINT, &ft_signalnewline);
	signal(SIGQUIT, &ft_signalquit);
	if (envp == NULL || argc != 1)
		return (EXIT_FAILURE);
	envp_cpy = cpytab(envp);
	exit_code = minishell_loop(&envp_cpy);
	if (envp_cpy != NULL)
		array_free(envp_cpy, 2);
	return (exit_code);
}
