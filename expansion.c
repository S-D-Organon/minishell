/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:10:36 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/13 21:43:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ambiguous_redirection(char *token)
{
	*m_exit_code() = 1;
	ft_putstr_fd(ERROR_PREFIX, 2);
	ft_putstr_fd(token, 2);
	ft_putendl_fd(": ambiguous redirect", 2);
}

//same as the classic expansion, but allow only one word at the end
t_list	*redirection_expansion(t_list *pipeline, char **envp)
{
	t_list	*expansion;
	t_list	*file_name;
	char	*content;

	content = ft_strdup(pipeline->content);
	if (content == NULL)
		return (NULL);
	expansion = ft_lstnew(content);
	if (expansion == NULL)
	{
		free(content);
		return (NULL);
	}
	file_name = classic_expansion(pipeline->next->content, envp);
	if (file_name == NULL || ft_lstsize(file_name) != 1)
	{
		if (ft_lstsize(file_name) != 1)
			ambiguous_redirection(pipeline->next->content);
		ft_lstclear(&expansion, &free);
		ft_lstclear(&file_name, &free);
		return (NULL);
	}
	ft_lstadd_back(&expansion, file_name);
	return (expansion);
}

//step 1: shell parameter expansion
//step 2: word splitting
//step 3: filename expansion(i.e.: *)
//step 4: quote removal
t_list	*classic_expansion(char *word, char **envp)
{
	char	*parameter_expanded;
	t_list	*word_splited;
	t_list	*filename_expanded;
	t_list	*quote_removed;

	parameter_expanded = parameter_expansion(word, envp);
	if (parameter_expanded == NULL)
		return (NULL);
	word_splited = word_split(parameter_expanded);
	free(parameter_expanded);
	if (word_splited == NULL)
		return (NULL);
	/*
	filename_expanded = filename_expansion(word_splited, envp);
	ft_lstclear(word_splited, &free);
	if (filename_expanded == NULL)
		return (NULL);
	//verify len($ alone for example), len=0 => content=NULL
	quote_removed = quote_removal(filename_expanded);
	ft_lstclear(filename_expanded, &free);
	return (quote_removed);
*/
	return (word_splited);
}