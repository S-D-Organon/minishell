//+=================================================================+
//|                                                                 |
//|    ______  ______   _____                                       |
//|   / ___\ \|  _ \ \ / _ \ \ _ __ __ _  __ _ _ __   ___  _ __     |
//|   \___ \\ \ | | \ \ | | \ \ '__/ _` |/ _` | '_ \ / _ \| '_ \    |
//|    ___) / / |_| / / |_| / / | | (_| | (_| | | | | (_) | | | |   |
//|   |____/_/|____/_/ \___/_/|_|  \__, |\__,_|_| |_|\___/|_| |_|   |
//|                                |___/                            |
//|                                                                 |
//+=================================================================+
//| project: minishell |
//+====================+
//| main_test.c |
//+=============+

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void	function_test(void);

const char	**supported_operators(void)
{
	static const char	*operators[] = {"<", "<<", ">", ">>", "|", "||", "&&", NULL};

	return (operators);
}

char	**global_envp(char *envp[])
{
	static char	**test;

	if (test == NULL)
		test = envp;
	return (test);
}

int	recursive_test(char c)
{
	if (c == 'c')
		return (1);
	printf("%c", c);
	return (recursive_test(c + 1));
}

int	main(int argc, char *argv[], char *envp[])
{
	printf("%d\n", recursive_test('a'));
}
