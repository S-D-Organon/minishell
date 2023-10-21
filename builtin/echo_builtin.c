/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:00:43 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/21 17:45:54 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	str_cmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (1);
	return (0);
}

int	echo_builtin(char **strings)
{
	char	option_n;

	if (strings == NULL)
		return (-1);
	option_n = 0;
	if (*strings != NULL)
		option_n = !str_cmp(*strings, "-n");
	if (option_n)
		strings += 1;
	while (*strings != NULL)
	{
		if (printf("%s", *strings) < 0)
			return (-1);
		strings += 1;
		if (*strings != NULL)
			printf(" ");
	}
	if (!option_n)
		printf("\n");
}
/*
int	main(int argc, char *argv[])
{
	//printf("%s", argv[0]);
	//printf("%s", argv[1]);
	echo_builtin(argv + 1);
}
*/
