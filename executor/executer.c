/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:46:36 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/26 20:32:06 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* em obras
nao sei oq fazer mais aqui
a principio a ideia esta posta
finalmente sem erros de codigo(modo burro) */

#include "../inc/minishell.h"

void	my_child(t_cmd cmds, int *fd)
{
	signal(SIGINT, handle_fork_sig);
	signal(SIGQUIT, SIG_IGN);
	if (data()->last_fd[0] != -1)
	{
		dup2(data()->last_fd[0], STDIN_FILENO);
		close(data()->last_fd[0]);
		close(data()->last_fd[1]);
	}
	else
		dup2(data()->std_fd[0], STDIN_FILENO);
	close(fd[0]);
	if (cmds.index < data()->n_cmd)
		dup2(fd[1], STDOUT_FILENO);
	else
		dup2(data()->std_fd[1], STDOUT_FILENO);
	redirct(cmds);
	if (is_path(cmds.cmd) == 1)
		find_builtins(cmds, 0);
	else
		find_builtins(cmds, 0);
	exit(data()->exit_status);
}

pid_t	creat_pid(t_cmd cmds, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("error: fork");
	if (pid == 0)
		my_child(cmds, fd);
	else
	{
		if (data()->last_fd[0] != -1)
		{
			close(data()->last_fd[0]);
			close(data()->last_fd[1]);
		}
		data()->last_fd[0] = fd[0];
		data()->last_fd[1] = fd[1];
	}
	return (pid);
}

void	pipe_create(int i, int *fd)
{
	pid_t	pids[20];
	int		e_status;

	while (++i < data()->n_cmd)
	{
		if (data()->n_cmd == (i + 1) && is_builtin(data()->cmds[i]))
			find_builtins(data()->cmds[i], 0);
		else
		{
			if (pipe(fd) == -1)
			{
				ft_putstr_fd("Error: ", 2);
				ft_putendl_fd(strerror(errno), 2);
				return ;
			}
			pids[i] = creat_pid(data()->cmds[i], fd);
		}
	}
	i = -1;
	while (++i < data()->n_cmd)
	{
		if (pids[i] != -1)
			waitpid(pids[i], &e_status, 0);
	}
}

void	executer(void)
{
	int	i;
	int	fd[2];

	i = -1;
	pipe_create(i, fd);
	return ;
}
