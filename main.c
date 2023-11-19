/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/19 15:18:48 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_not_space(char c)
{
	return (!isspace(c));
}

//step 1: read input
//step 2: lexical analysis(convert input into tokens)
//step 3: syntaxic analysis(interpret tokens)
//
int	main(void)
{
	char	*input;
	char	**token;
	int	i;

	input = readline(PROMPT);
	while (input != NULL)
	{
		add_history(input);
		token = split_context(input, &is_token);
		free(input);
		if (token == NULL)
			break ;
		//parser(token);
		i = 0;
		while (token[i] != NULL)
		{
			printf("[%d]:%s\n", i, token[i]);
			fflush(stdout);
			i++;
		}
		array_free(token, 2);
		input = readline(PROMPT);
	}
	return (EXIT_SUCCESS);
}
