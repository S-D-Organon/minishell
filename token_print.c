/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:30:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/29 22:47:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_print(t_list *token)
{
	int	i;

	i = 0;
	while (token != NULL)
	{
		printf("token %d: %s\n", i, (char *)token->content);
		token = token->next;
		i++;
	}
}