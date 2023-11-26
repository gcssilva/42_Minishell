/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:43:05 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/26 19:46:34 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

int	is_builtin(t_cmd cmds)
{
	if (!ft_strncmp(cmds.cmd, "pwd", 3) && ft_strlen(cmds.cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "echo", 4) && ft_strlen(cmds.cmd) == 4)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "env", 3) && ft_strlen(cmds.cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "exit", 4) && ft_strlen(cmds.cmd) == 4)
		return (1);
	else if (!ft_strncmp(cmds.cmd, "cd", 2))
		return (1);
	// else if (!ft_strncmp(cmds.cmd, "export", 6))
	// 	func_export(cmds);
	else if (!ft_strncmp(cmds.cmd, "unset", 5))
		return (1);
	return (0);
}
