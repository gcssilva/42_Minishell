/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:57 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/22 18:17:14 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	treat_exit_arg(char *str, int i);
void	func_exit(t_cmd *cmds);
int		is_numeric(char *arg);
void	close_fd(void);
void	clean_struct(void);

void	treat_exit_arg(char *str, int i)
{
	int			s;
	int			len;
	long int	n;

	s = 0;
	n = 0;
	len = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		s = str[0];
	if ((s && len > 20) || len > 19)
		return ;
	i = -1;
	if (s != 0)
		i++;
	while (str[++i])
	{
		if (n >= BIG_INT && (str[i] - 48) > 7)
			return ;
		n = (n * 10) + (str[i] - 48);
	}
	if (s == '-')
		n = -n;
	close_fd();
	clean_env();
	exit (n % 256);
}

void	func_exit(t_cmd *cmds)
{
	ft_putendl_fd("exit", 1);
	if (cmds->arg[1] && cmds->arg[2])
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		data()->exit_status = 1;
	}
	else if (cmds->arg[1])
	{
		if (is_numeric(cmds->arg[1]))
			treat_exit_arg(cmds->arg[1], -1);
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmds->arg[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		close_fd();
		clean_struct();
		clean_env();
		exit (2);
	}
	else
	{
		close_fd();
		clean_struct();
		clean_env();
		exit (0);
	}
}

int	is_numeric(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

void	close_fd(void)
{
	if (data()->last_fd[0] != -1)
	{
		close(data()->last_fd[0]);
		close(data()->last_fd[1]);
	}
	if (dup2(data()->std_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(data()->std_fd[0]);
	if (dup2(data()->std_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(data()->std_fd[1]);
}

void	clean_struct(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data()->n_cmd)
	{
		j = -1;
		while (data()->cmds[i]->arg[++j] != NULL)
			free(data()->cmds[i]->arg[j]);
		j = -1;
		while (data()->cmds[i]->red[++j] != NULL)
			free(data()->cmds[i]->red[j]);
		j = -1;
		while (data()->cmds[i]->order[++j] != NULL)
			free(data()->cmds[i]->order[j]);
		free(data()->cmds[i]->cmd);
		free(data()->cmds[i]);
	}
	free(data()->cmds);
}
