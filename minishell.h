/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:34:29 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/14 21:55:12 by gdornic          ###   ########.fr       */
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
# define O_CREAT_PERMISSIONS S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
# define HERE_DOC_PROMPT "> "

typedef struct s_stream
{
	int	input;
	int	output;
	int	next_input;
	int	previous_output;
	int	saved_stdin_fd;
	int	saved_stdout_fd;
}	t_stream;

//array free
void	array_free(void *root, unsigned int dimension);

//delete node
void	delete_node(t_list **list, t_list *node);

//str merge
char	*str_merge(char *s1, char *s2);

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
int	is_or(char *str);
int	is_and(char *str);
int	is_executable(char *path_name);
int	is_builtin(char *cmd);

//function variables
const char	**operators_set(void);
t_stream	*m_stream(void);
int			*m_exit_code(void);
int			*m_last_exit_code(void);

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

//pipeline execution
int	pipeline_execution(t_list *pipeline, char ***envp_ptr, int exit_status);

//command execution
t_list	*next_redirection_operator(t_list *command);
int	command_execution(t_list *command, char ***envp_ptr, int exit_status, int builtin_create_subshell);

//builtin execution
int	builtin_execution(char **cmd, char ***envp_ptr, int builtin_create_subshell);

//program execution
int	program_execution(char **cmd, char **envp);

//stream
int		m_stream_use(void);
int		m_stream_redirect(t_list *command);
int		pipe_set(int last);
void	m_stream_set(void);

//redirection
int	input_redirect(char *file_name);
int	here_doc(char *delimiter);
int	output_redirect(char *file_name);
int	output_redirect_append(char *file_name);

//expansion
t_list	*redirection_expansion(t_list *pipeline, char **envp);
t_list	*classic_expansion(char *word, char **envp);

//parameter expansion
char	*parameter_expansion(char *word, char **envp);

//word split
t_list *word_split(char *word);

//filename expansion
t_list	*filename_expansion(t_list *token);

#endif