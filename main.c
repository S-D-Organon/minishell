/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/29 22:48:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//step 1: read input
//step 2: lexical analysis(convert input into tokens)
//step 3: syntaxic analysis(interpret tokens)
//
int	main(void)
{
	char	*input;
	t_list	*token;

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
		//errno = parser(token);
		ft_lstclear(&token, &free);
		//if (errno == ENOMEM)
		//	break ;
		input = readline(PROMPT);
	}
	return (errno);
}
