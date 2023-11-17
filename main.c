/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:52 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/13 08:16:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	char	***cmd;

	input = readline(PROMPT);
	while (input != NULL)
	{
		add_history(input);
		cmd = input_parser(input);
		free(input);
		if (cmd == NULL)
			break ;
		cmd_parser(cmd);
		array_free(cmd, 2);
		input = readline(PROMPT);
	}
	return (EXIT_SUCCESS);
}
