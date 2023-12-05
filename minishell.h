/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:34:29 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/05 21:15:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <libft.h>
# define ERROR_PREFIX "minishell: "
# define PROMPT "minishell> "

//array free
void	array_free(void *root, unsigned int dimension);

//tokenizer
t_list	*tokenizer(char *input);

//print error
void	print_error(char *prefix, char *error, char *suffix);

//definitions
int	is_space(int c);
int	is_metacharacter(int c);
int	is_operator(char *str);
int	is_redirection_operator(char *str);
int	is_control_operator(char *str);
int	is_pipe(char *str);
int	is_list_operator(char *str);
int	is_left_bracket(char *str);
int	is_right_bracket(char *str);
int	is_word(char *str);
int	is_bracket(char *str);

//function variables
const char	**operators_set(void);

//token print
void	token_print(t_list *token);

//parser
int	parser(t_list *token, char ***envp_ptr);

//syntax_rules
int	syntax_error(char *content);
int	bracket_count_rule(char *content, char *next_content);
int	syntax_rules(t_list *token);

//execution
int	execution(t_list *token, char ***envp_ptr, int exit_status);

#endif
