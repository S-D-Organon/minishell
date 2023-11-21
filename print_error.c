/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:56:50 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/20 10:05:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	print_error(char *prefix, char *error, char *suffix)
{
	if (prefix != NULL)
		write(2, prefix, str_len(prefix));
	if (error != NULL)
		write(2, error, str_len(error));
	if (suffix != NULL)
		write(2, suffix, str_len(suffix));
	write(2, "\n", 1);
}
