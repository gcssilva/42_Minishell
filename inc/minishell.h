/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:57:07 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/30 13:11:33 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BIG_INT 922337203685477580
# define MAX_RED 100
# define MAX_ARG 100
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <dirent.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>

typedef struct s_cmd
{
	int		index;
	char	*red[MAX_RED];
	char	*order[MAX_RED];
	char	*cmd;
	char	*arg[MAX_ARG];
}	t_cmd;

typedef struct s_data
{
	int		path;
	int		tmp_f;
	int		exit_status;
	int		n_cmd;
	int		std_fd[2];
	int		last_fd[2];
	char	**copy_env;
	char	**ord_env;
	t_cmd	**cmds;
}	t_data;

//find_builtin
void	find_builtins(t_cmd *cmds);
void	clean_exit(void);

//func_cd
char	*home(char **env);
void	cd_error(char *token);
void	func_cd(t_cmd *cmds);

//func_echo
void	last_space(char **arg, int i);
void	echo_print(t_cmd *cmd, int flag);
void	func_echo(t_cmd *cmds);

//func_env
void	func_env(t_cmd	*cmds);

//func_exec
int		check(char *cmd);
char	*find_path(char *cmd, char **env, int i);
void	func_exec(t_cmd *cmds);

//func_exit
void	treat_exit_arg(char *str, int i, int s);
void	func_exit(t_cmd *cmds);
int		is_numeric(char *arg);
void	close_fd(void);
void	clean_struct(void);

//func_export
int		valid_var(char *var);
void	add_var(t_cmd *cmds, int a);
void	func_export(t_cmd *cmds);
char	**add_new_var(char **env, char *var);

//func_pwd
void	func_pwd(void);

//func_unset
int		var_len(char *var);
int		exist_var(t_cmd *cmds, int a);
void	func_unset(t_cmd *cmds);
char	**delete_arg(t_cmd *cmds, char **env, int a);

//copy_env
void	clean_env(void);
void	copy_env(char **input);
void	ord_env(char **input);
void	asci_ord(char **input);

//executor_utils
void	print_export(char **env);
int		is_path(char *cmd);
int		is_builtin(t_cmd *cmds);

//executor_utils 2
int		check_unset(char *str);
void	check_export(t_cmd *cmds, int a);
void	ft_wait(pid_t *pids);
int		clean_all(void);

//executor
void	my_child(t_cmd *cmds, int *fd);
pid_t	creat_pid(t_cmd *cmds, int *fd);
void	pipe_create(int i, int *fd);
void	last_cmd(int i);
void	executor(void);

//lexer
int		check_pipes(char *input, int flag);
int		check_quotes(char *input);
int		lexer(char *input);
int		verify_redir(char *input);
int		lex_err(int i);

//parse_red
void	write_redir(char *r_file, int r);
void	add_redir(char *input, int *i);

//parse_utils
void	n_cmds(char	*input);
int		ft_isblank(int c);
int		ft_isredir(int c);
void	inicialize_stuct(void);

//parse_var
char	*copy_var(char *cmd, char *var);
char	*get_var(char *cmd, char *var);
char	*exp_var(char *cmd, char *input, int *i);
char	*exp_exs(char *cmd);

//parse
char	*cjoin(char *str, char c);
int		split_cmd(char *str, int flag);
char	*quote_join(char *cmd, char *input, int *i);
int		get_pos(char **ar);
void	parse_input(char *input);

//redir
void	check_outfile(char *red, int flag);
void	check_infile(char *red);
void	check_heredoc(char *delimiter);
void	redirct(t_cmd *cmds);
void	do_heredoc(char *delimiter);

//minishell
t_data	*data(void);
void	start_minishell(int ac, char **av, char **env);

//signals
void	sig(int flag);
void	handle_sig(int sig);
void	handle_fork_sig(int sig);
void	fork_heredoc(int sig);

#endif
