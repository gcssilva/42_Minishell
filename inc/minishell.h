/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:57:07 by gsilva            #+#    #+#             */
/*   Updated: 2023/12/07 16:42:38 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>

extern int	g_sig;

typedef struct s_cmd
{
	int		index;
	char	*red[10];
	char	*order[10];
	char	*cmd;
	char	*arg[10];
}	t_cmd;

typedef struct s_data
{
	int		temp_file;
	int		exit_status;
	int		n_cmd;
	int		std_fd[2];
	int		last_fd[2];
	char	**copy_env;
	t_cmd	*cmds;
}	t_data;

//find_builtin
void	find_builtins(t_cmd cmds);

//func_cd
char	*home(char **env);
void	cd_error(char *token);
void	func_cd(t_cmd cmds);

//func_echo
int		last_space(char **arg, int i);
void	echo_print(t_cmd cmd, int flag);
void	func_echo(t_cmd cmds);

//func_env
void	func_env(void);

//func_exec
int		check(char *cmd);
char	*find_path(char *cmd, char **env, int i);
void	func_exec(t_cmd cmds);

//func_exit
int		treat_exit_arg(char *str);
void	func_exit(t_cmd cmds);
int		is_numeric(char *arg);

//func_export
int		valid_var(char *var);
void	delete_arg(t_cmd cmds);
void	add_var(t_cmd cmds);
void	func_export(t_cmd cmds);

//func_pwd
void	func_pwd(void);

//func_unset
int		var_len(char *var);
int		exist_var(t_cmd cmds);
void	func_unset(t_cmd cmds);

//copy_env
void	copy_env(char **input);

//executor_utils
void	print_str(char *str);
int		is_path(char *cmd);
int		is_builtin(t_cmd cmds);

//executor_utils 2
int	check_unset(char *str);
int	exist_export(t_cmd cmds);

//executor
void	my_child(t_cmd cmds, int *fd);
pid_t	creat_pid(t_cmd cmds, int *fd);
void	pipe_create(int i, int *fd);
void	last_cmd(int i);
void	executor(void);

//lexer
int		check_pipes(char *input, int flag);
int		check_quotes(char *input);
int		lexer(char *input);

//parse_red
void	write_redir(char *r_file, int r);
void	add_redir(char *input, int *i);

//parse_utils
void	n_cmds(char	*input);
int		ft_isblank(int c);
int		ft_isredir(int c);

//parse_var
char	*copy_var(char *cmd, char *var);
char	*get_var(char *cmd, char *var);
char	*exp_var(char *cmd, char *input, int *i);

//parse
char	*cjoin(char *str, char c);
int		split_cmd(char *str, int flag);
char	*quote_join(char *cmd, char *input, int *i);
int		get_pos(char **ar);
void	parse_input(char *input);

//redir
void	check_outfile(char *red, int flag);
void	check_infile(char *red);
void	w_heredoc(char *delimiter);
void	check_heredoc(char *delimiter);
void	redirct(t_cmd cmds);

//minishell
t_data	*data(void);
void	clean_struct(void);

//signals
void	sig(int flag);
void	handle_sig(int sig);
void	handle_fork_sig(int sig);
void	end_loop(int sig);

#endif
