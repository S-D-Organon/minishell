/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 03:40:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/16 05:26:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*next_mark(char *word)
{
	while (*word != '\0' && *word != '\x1D')
		word++;
	return (word);
}

char	*next_quote(char *word, char previous_quote)
{
	while (*word != '\0' && *word != previous_quote)
		word++;
	return (word);
}

char	*quote_purge(char *word)
{
	char	*word_cpy;
	char	*purge;
	char	*quote;

	if (word == NULL)
		return (NULL);
	word_cpy = word;
	quote = next_quote(word, *quote);
	purge = ft_strdup("");
	while (*word != '\0')
	{
		purge = str_merge(purge, ft_substr(word, 0, quote - word));
		if (purge == NULL)
			break ;
		word = quote + (*quote == '\'' || *quote == '"');
		quote = next_quote(word, *quote);
		purge = str_merge(purge, ft_substr(word, 0, quote - word));
		if (purge == NULL)
			break ;
		quote = next_quote(word, *quote);
		purge = str_merge(purge, ft_substr(word, 0, quote - word));
	}
	free(word_cpy);
	return (purge);
}

//use with dynamic allocation
char	*quote_remove(char *word)
{
	char	*unquoted_word;
	char	*word_cpy;
	char	*separator;

	if (word == NULL)
		return (NULL);
	word_cpy = word;
	unquoted_word = ft_strdup("");
	separator = next_mark(word);
	while (*word != '\0')
	{
		unquoted_word = str_merge(unquoted_word, quote_purge(ft_substr(word, 0, separator - word)));
		if (unquoted_word == NULL)
			break ;
		word = separator + (separator == '\x1D');
		separator = next_mark(word);
		unquoted_word = str_merge(unquoted_word, ft_substr(word, 0, separator - word));
		if (unquoted_word == NULL)
			break ;
		word = separator + (separator == '\x1D');
		separator = next_mark(word);
	}
	free(word_cpy);
	return (unquoted_word);
}