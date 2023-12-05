/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/05 21:13:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//step 1: read input
//step 2: lexical analysis(convert input into tokens)
//step 3: syntaxic analysis(check token positioning)
//step 4: interpret tokens into list of pipeline(s)
//step 5: execute pipeline(s)
int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	t_list	*token;

	(void)argc;
	(void)argv;
	input = readline(PROMPT);
	errno = 0;
	while (input != NULL)
	{
		add_history(input);
		token = tokenizer(input);
		free(input);
		if (errno == ENOMEM)
			break ;
		token_print(token);
		if (token != NULL)
			errno = parser(token, &envp);
		printf("errno: %d\n", errno);
		ft_lstclear(&token, &free);
		if (errno == ENOMEM)
			break ;
		input = readline(PROMPT);
	}
	return (errno);
}
