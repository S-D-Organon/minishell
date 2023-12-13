/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 04:04:28 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/13 07:15:54 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parameter_len(char *str)
{
	int	len;

	len = 0;
	if (*str == '$' && *(str + 1) == '?')
		return (2);
	if (*str == '$')
		len = 1;
	while (str[len])
	{
		if (str[len] == '*' || str[len] == '$' || str[len] == '?')
			break ;
		len++;
	}
	return (len);
}

char	*next_parameter(char *word)
{
	char	quote;

	quote = '\0';
	while (*word != '\0')
	{
		if (quote != '\'' && *word == '$' && parameter_len(word) > 1)
			break ;
		if (quote == '\0' && *word == '\'')
			quote = '\'';
		else if (quote == '\0' && *word == '"')
			quote = '"';
		else if (quote == '\'' && *word == '\'')
			quote = '\0';
		else if (quote == '"' && *word == '"')
			quote = '\0';
		word++;
	}
	return (word);
}

char	*parameter_search(char *parameter, char **envp)
{
	char	*envp_parameter;
	int		i;

	if (*parameter == '\0')
		return (ft_strdup(""));
	if (*(parameter + 1) == '?')
		return (ft_itoa(*m_exit_code()));
	envp_parameter = str_merge(ft_substr(parameter, 1, parameter_len(parameter) - 1), ft_strdup("="));
	if (envp_parameter == NULL)
		return (NULL);
	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], envp_parameter, ft_strlen(envp_parameter)))
		i++;
	if (envp[i] == NULL)
		return (ft_strdup(""));
	return (ft_strdup(envp[i] + ft_strlen(envp_parameter)));
}

char	*parameter_expansion(char *word, char **envp)
{
	char	*expansion;
	char	*position;
	char	*parameter;

	parameter = next_parameter(word);
	expansion = str_merge(ft_substr(word, 0, parameter - word), \
	parameter_search(parameter, envp));
	if (expansion == NULL)
		return (NULL);
	position = parameter + parameter_len(parameter);
	while (*position != '\0')
	{
		parameter = next_parameter(position);
		expansion = str_merge(expansion, ft_substr(word, position - word, parameter - position));
		if (expansion == NULL)
			return (NULL);
		expansion = str_merge(expansion, parameter_search(parameter, envp));
		if (expansion == NULL)
			return (NULL);
		position = parameter + parameter_len(parameter);
	}
	return (expansion);
}
