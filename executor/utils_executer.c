/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/18 22:56:37 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_redirec(char *cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '>>' || cmd[i] == '<<')
			return (1);
		i++;
	}
	return (0);
}

int	is_path(char *cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == '/' || cmd[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	just_one_cmd(char *copy_env)
{
	int	i;
	
	i = 0;
	while(++i < data()->n_cmd)
	{
		if (!ft_strncmp(data()->cmds[i].cmd, "/", 1))
		{
			find_builtins(data()->cmds[i].cmd, copy_env, 1);
			break;
		}
		else
		{
			find_builtins(data()->cmds[i].cmd, copy_env, 0);
			return ;
		}
	}
}
