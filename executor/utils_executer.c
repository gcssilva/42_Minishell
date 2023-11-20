/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/17 09:49:14 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_redirec(void)
{
	int	i;

	i = 0;
	if (data()->cmds[i]->in[i] == NULL || data()->cmds[i]->out[i] == NULL\
		|| data()->cmds[i]->ap[i] == NULL || data()->cmds[i]->delimiters[i] == NULL)
		return (0);
	return (1);
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

void	just_one_cmd(char *cmds, char *args, char *copy_env)
{
	int	i;
	
	i = 0;
	while(cmds[i++])
	{
		if (!ft_strncmp(cmds[i], "/", 1))
		{
			find_builtins(cmds, 1);
			break;
		}
		else
		{
			find_builtins(cmds, 0);
			return ;
		}
	}
}
