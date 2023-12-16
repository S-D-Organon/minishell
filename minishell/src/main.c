/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:46 by lseiberr          #+#    #+#             */
/*   Updated: 2023/12/16 15:11:55 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_init_env(char **env, t_data *data)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		i++;
	}
	data->sizeenv = i;
	data->env[i] = NULL;
}

void	ft_init_args(t_data *data, char *input)
{
	int	i;

	i = 0;
	data->oldpwd = NULL;
	data->arg = ft_split(input, ' ');
	free(input);
	while (data->arg[i])
		i++;
	data->sizedata = i - 1;
}

int	main(int ac, char **ag, char **env)
{
	t_data	*data;
	char	*input;

	(void)ac;
	(void)ag;
	data = malloc(sizeof(t_data));
	ft_init_env(env, data);
	//signal(SIGINT, &ft_signalnewline);
	while (1)
	{
		input = readline("minishell : ");
		if (input != NULL && input[0] != '\0')
		{
			ft_init_args(data, input);
			if (ft_strcmp(data->arg[0], "unset") == 0)
				unset_builtin(data->arg + 1, &env);
			else if (ft_strcmp(data->arg[0], "env") == 0)
				env_builtin(data->arg + 1, &env);
			else if (ft_strcmp(data->arg[0], "export") == 0)
				export_builtin(data->arg + 1, &env);
			else if (ft_strcmp(data->arg[0], "cd") == 0)
				cd_builtin(data->arg + 1, &env);
			else if (ft_strcmp(data->arg[0], "pwd") == 0)
				pwd_builtin(data->arg + 1, &env);
			else if (ft_strcmp(data->arg[0], "echo") == 0)
				echo_builtin(data->arg + 1, &env);
		}
	}
}
