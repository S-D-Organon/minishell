/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:57:02 by lseiberr          #+#    #+#             */
/*   Updated: 2023/11/13 12:14:14 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

extern char	**environ;

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	**init_env(char **environ, char **env)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	return (env);
}

char	**sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	i = 0;
	j = i + 1;
	while (env[i + 1])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				tmp = env[j];
				env[j] = env[i];
				env[i] = tmp;
			}
			j++;
		}
		i++;
	}
	env[i - 1] = env[i];
	env[i] = NULL;
	return (env);
}
static int	count_words(char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*tmp;
	size_t	i;

	tmp = (char *) pointer;
	i = 0;
	while (i < count)
	{
		tmp[i] = (char) value;
		i++;
	}
	return (pointer);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	if (!size || !count)
		return (malloc(0));
	tot_size = size * count;
	if ((tot_size / size != count) || (tot_size / count != size))
		return (NULL);
	dst = malloc(tot_size);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, tot_size);
	return (dst);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s) && split)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	return (split);
}


char	**ft_export(void)
{
	char	**env;
	char	*join;
	int		i;

	env = NULL;
	i = 0;
	join = "declare -x ";
	env = init_env(environ, env);
	env = sort_env(env);
	while (env[i])
	{
		env[i] = ft_strjoin(join, env[i]);
		i++;
	}
	return (env);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	**export_builtin(char **env, char **args)
{
	int		i;
	int		j;
	int		k;
	char	**new_env;
	char	tmp;
	char	**temp;

	i = 0;
	j = 1;
	k = 0;
	while (env[i])
		i++;
	while (args[j])
		j++;
	new_env = malloc(sizeof(char *) * (i + j + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	j = 1;
	while (args[j])
	{
		if (ft_strchr(args[j], '=') == 0)
		{
			temp = ft_split(args[j], '=');
			new_env[i] = ft_strdup(temp[0]);
			new_env[i] = ft_strjoin(args[j], "='");
			new_env[i] = ft_strjoin(args[j], "\"");
			while (temp[k])
			{
				new_env[i] = ft_strjoin(new_env[i], temp[k]);
				k++;
			}
			new_env[i] = ft_strjoin(new_env[i], "'");
		}
		else
			args[j] = ft_strjoin(args[j], "=''");
			new_env[i] = ft_strdup(args[j]);
			i++;
			j++;
	}
	return (new_env);
}

int	main(int ac, char **ag)
{
	int		i;
	char	**env;

	env = ft_export();
	env = export_builtin(env, ag);
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		free(env[i]);
		i++;
	}
	free(env);
}

