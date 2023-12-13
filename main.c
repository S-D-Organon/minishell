/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/13 07:23:20 by gdornic          ###   ########.fr       */
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
	int		exit_status;
	char	*input;
	t_list	*token;

	input = readline(PROMPT);
	exit_status = 0;
	while (input != NULL)
	{
		add_history(input);
		errno = 0;
		token = tokenizer(input);
		free(input);
		if (errno == ENOMEM)
			break ;
		if (token != NULL)
			exit_status = parser(token, envp_ptr);
		ft_lstclear(&token, &free);
		if (errno == ENOMEM || exit_status)
			break ;
		input = readline(PROMPT);
	}
	return (*m_exit_code());
}

int	main(int argc, char *argv[], char *envp[])
{
	if (envp == NULL || argc != 1)
		return (EXIT_FAILURE);
	return (minishell_loop(&envp));
}
