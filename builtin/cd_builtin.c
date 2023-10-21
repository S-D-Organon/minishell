/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:16:51 by lseiberr          #+#    #+#             */
/*   Updated: 2023/10/21 16:48:56 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cd_builtin(char *path)
{
	if (path == NULL)
	{
		path = getenv("Users");
		if (path == NULL)
		{
			perror("cd");
			return (1);
		}
	}
	if (chdir(path) != 0)
	{
		perror ("cd");
		return (1);
	}
	return (0);
}
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	main(int argc, char *argv[])
{
	char	current_directory[PATH_MAX];
	char	*path;
	int		status;

	if (argc >= 2 && strcmp(argv[1], "cd") == 0)
	{
		if (getcwd(current_directory, PATH_MAX) != NULL)
		{
			printf("Répertoire courant : %s\n", current_directory);
		}
		else
		{
			perror("getcwd");
		}
		if (argc >= 3)
		{
			path = ft_strjoin(current_directory, "/");
			path = ft_strjoin(path, argv[2]);
			printf("Répertoire voulu : %s\n", path);
			status = cd_builtin(path);
			if (status != 0)
			{
				return (1);
			}
		}
		else
		{
			status = cd_builtin(NULL);
			if (status != 0)
			{
				return (1);
			}
		}
		status = open("test1", O_CREAT, 0777);
	}
	return (0);
}
*/
