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

extern int	sig_n;

//A struct s_cmd guarda as informacoes de 1 comando ate o proximo pipe ou ate o fim do input
//a variavel *delimiters[] representa um array de delimitadores de heredoc '<<'
//a variavel *cmd contem apenas o nome do comando
//a variavel **arg representa um array de argumentos passados ao comando (arg[0] sempre contem o nome do comando)

typedef struct	s_cmd
{
	int		index;
	char	*red[10];
	char	*order[10];
	char	*cmd;
	char	*arg[10];
}	t_cmd;

typedef struct s_data
{
	int		exit_status;
	int		n_cmd;
	char	**copy_env;
	int		std_fd[2];
	int		last_fd[2];
	t_cmd	*cmds;
}	t_data;

t_data	*data(void);

void	copy_env(char **input);

//builtins
void	find_builtins(t_cmd cmd);
void	func_pwd(void);
void	func_echo(t_cmd cmd);
void	func_cd(t_cmd cmds);
void	func_env(int flag);
void	func_unset(t_cmd cmds);
void    func_export(t_cmd cmds);
void	func_exit(t_cmd cmds);
void	func_exec(t_cmd cmds);
void	just_one_cmd(char **copy_env);

//executor
void	executer(void);
void	redirct(t_cmd cmds);
int		is_path(char *cmd);
void	print_str(char *str);
int		is_numeric(char *arg);
void	delete_arg(t_cmd cmds);
int		exist_var(t_cmd cmds, int flag);
int		var_len(char *var);

//parse
void	parse_input(char *input);
void	n_cmds(char	*input);
int		check_quotes(char *input);
int		ft_isblank(int c);
int		ft_isredir(int c);
int		split_cmd(char *str, int flag);
char	*quote_join(char *cmd, char *input, int *i);
char	*copy_var(char *cmd, char *var);
char	*exp_var(char *cmd, char *input, int *i);
int		check_pipes(char *input);
int		lexer(char *input);
char	*cjoin(char *str, char c);

void	sig(int flag);
void	handle_sig(int sig);
void	handle_fork_sig(int sig);
void	end_loop(int sig);

int		is_builtin(t_cmd cmds);

#endif
