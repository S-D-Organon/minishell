/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:10:36 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/13 07:23:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//same as the classic expansion, but allow only one word at the end
t_list	*redirection_expansion(char *word, char **envp)
{
}

//step 1: shell parameter expansion
//step 2: word splitting
//step 3: filename expansion(i.e.: *)
//step 4: quote removal
t_list	*classic_expansion(char *word, char **envp)
{
	char	*parameter_expanded;
	char	**word_splited;
	char	**filename_expanded;
	t_list	*quote_removed;

	parameter_expanded = parameter_expansion(word, envp);
	if (parameter_expanded == NULL)
		return (NULL);
	word_splited = word_splitting(parameter_expanded);
	free(parameter_expanded);
	if (word_splited == NULL)
		return (NULL);
	filename_expanded = filename_expansion(word_splited, envp);
	array_free(word_splited, 2);
	if (filename_expanded == NULL)
		return (NULL);
	//verify len($ alone for example), len=0 => content=NULL
	quote_removed = quote_removal(filename_expanded);
	array_free(filename_expanded, 2);
	return (quote_removed);
}