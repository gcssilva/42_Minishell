/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:46:36 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/02 11:36:09 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* em obras
nao sei oq fazer mais aqui
a principio a ideia esta posta */


#include "../inc/minishell.h"

void	my_second_child(int *fd)
{
	int	i;

	i = 0;
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (is_path(cmd) == 1);
	{
		find_builtins(data()->cmds[i], data()->env, 1);
		close(fd[0]);
		return ;
	}
	find_builtins(data()->cmds[i], data()->env, 0);
}

void	my_first_child(int *fd)
{
	int	i;

	i = 0;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (is_path(data()->cmds[i]) == 1);
	{
		find_builtins(data()->cmds[i], data()->env, 1);
		return ;
	}
	find_builtins(data()->cmds[i], data()->env, 0);
}

void	creat_pid(char *cmd, int *fd, int flag)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		perror("error : fork");
	if (pid == 0 && flag == 0)
		my_firt_child(fd);
	else if (pid == 0 && flag == 1)
		my_second_child(fd);

}

void	executer(char *cmd, char *arg, char ***env)
{
	int	i;
	int flag;
	int	fd[2];
	
	i = 0;
	flag = 0;
	if (data()->n_cmd == 0)
	{
		while(cmd[i])
		{
			if (cmd[i] == '/' || cmd[i] == '.')
			{
				find_builtins(cmd, env, 1);
				break;
			}
			else
			{
				find_builtins(cmd, env, 0);
				return ;
			}
			i++;
		}
	}
	if (pipe(fd) == -1)
	{
		t_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr("\n");
	}
	while (cmd[i] && arg[i])
	{
		if (flag == 0)
		{
			creat_pid(cmd[i], fd, 0);
			flag = 1;	
		}
		else if (flag == 1)
		{
			creat_pid(arg[i], fd, 1);
		}
		i++;
	}
	close(fd[1]);
	close(fd[0]);
}
