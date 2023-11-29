/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:56:50 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/29 22:44:47 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
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
		write(2, prefix, ft_strlen(prefix));
	if (error != NULL)
		write(2, error, ft_strlen(error));
	if (suffix != NULL)
		write(2, suffix, ft_strlen(suffix));
	write(2, "\n", 1);
}
