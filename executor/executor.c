/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:46:36 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/22 18:03:36 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	my_child(t_cmd *cmds, int *fd);
pid_t	creat_pid(t_cmd *cmds, int *fd);
void	pipe_create(int i, int *fd);
void	last_cmd(int i);
void	executor(void);

void	my_child(t_cmd *cmds, int *fd)
{
	sig(1);
	if (data()->last_fd[0] != -1)
	{
		dup2(data()->last_fd[0], STDIN_FILENO);
		close(data()->last_fd[0]);
		close(data()->last_fd[1]);
	}
	else
	{
		dup2(data()->std_fd[0], STDIN_FILENO);
	}
	close(fd[0]);
	if (cmds->index < data()->n_cmd)
		dup2(fd[1], STDOUT_FILENO);
	else
		dup2(data()->std_fd[1], STDOUT_FILENO);
	redirct(cmds);
	find_builtins(cmds);
	close_fd();
	clean_env();
	close(fd[1]);
	exit(0);
}

pid_t	creat_pid(t_cmd *cmds, int *fd)
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
	pid_t	pids[10];
	int		e_status;

	while (++i < data()->n_cmd && data()->cmds[i]->cmd)
	{
		if (data()->n_cmd == (i + 1) && is_builtin(data()->cmds[i]))
			last_cmd(i);
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
		waitpid(pids[i], &e_status, 0);
		if (WIFEXITED(e_status))
			data()->exit_status = WEXITSTATUS(e_status);
	}
}

void	last_cmd(int i)
{
	redirct(data()->cmds[i]);
	find_builtins(data()->cmds[i]);
}

void	executor(void)
{
	int	fd[2];

	data()->std_fd[0] = dup(STDIN_FILENO);
	data()->std_fd[1] = dup(STDOUT_FILENO);
	data()->last_fd[0] = -1;
	pipe_create(-1, fd);
	close_fd();
	clean_struct();
	remove(".tmp_f.txt");
}
