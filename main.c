/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/10 03:38:53 by gdornic          ###   ########.fr       */
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
		if (errno == ENOMEM)
			break ;
		input = readline(PROMPT);
	}
	printf("%d\n", exit_status);
	return (*m_exit_code());
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	if (envp == NULL)
		return (EXIT_FAILURE);
	return (minishell_loop(&envp));
}
