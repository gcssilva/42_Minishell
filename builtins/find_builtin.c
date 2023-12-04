/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:08:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/12/04 18:24:47 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	find_builtins(t_cmd cmds)
{
	if (!ft_strncmp(cmds.cmd, "pwd", 3) && ft_strlen(cmds.cmd) == 3)
		func_pwd();
	else if (!ft_strncmp(cmds.cmd, "echo", 4) && ft_strlen(cmds.cmd) == 4)
		func_echo(cmds);
	else if (!ft_strncmp(cmds.cmd, "env", 3) && ft_strlen(cmds.cmd) == 3)
		func_env(0);
	else if (!ft_strncmp(cmds.cmd, "exit", 4) && ft_strlen(cmds.cmd) == 4)
		func_exit(cmds);
	else if (!ft_strncmp(cmds.cmd, "cd", 2) && ft_strlen(cmds.cmd) == 2)
		func_cd(cmds);
	else if (!ft_strncmp(cmds.cmd, "export", 6) && ft_strlen(cmds.cmd) == 6)
		func_export(cmds);
	else if (!ft_strncmp(cmds.cmd, "unset", 5) && ft_strlen(cmds.cmd) == 5)
		func_unset(cmds);
	else
		func_exec(cmds);
}
