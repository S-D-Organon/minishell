/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:05:45 by gdornic           #+#    #+#             */
/*   Updated: 2023/11/30 12:06:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	**operators_set(void)
{
	static const char	*operators[] = (const char *[]){"<", "<<", ">", ">>", \
		"|", "||", "&&", "(", ")", NULL};

	return (operators);
}