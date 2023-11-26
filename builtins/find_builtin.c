/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:08:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/26 20:04:10 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta argumentos para linkar isto com o resto do projeto
  mas fora isso esta pronto
builtins finalizado porem sem testes
*/

static void	cmd_mode(t_cmd cmds)
{
	if (!ft_strncmp(cmds.cmd, "pwd", 3) && ft_strlen(cmds.cmd) == 3)
		func_pwd();
	else if (!ft_strncmp(cmds.cmd, "echo", 4) && ft_strlen(cmds.cmd) == 4)
		func_echo(cmds);
	else if (!ft_strncmp(cmds.cmd, "env", 3) && ft_strlen(cmds.cmd) == 3)
		func_env();
	else if (!ft_strncmp(cmds.cmd, "exit", 4) && ft_strlen(cmds.cmd) == 4)
		func_exit(cmds);
	else if (!ft_strncmp(cmds.cmd, "cd", 2))
		func_cd(cmds);
	// else if (!ft_strncmp(cmds.cmd, "export", 6))
	// 	func_export(cmds);
	else if (!ft_strncmp(cmds.cmd, "unset", 5))
		func_unset(cmds);
	else
		func_exec(cmds);
}

void	find_builtins(t_cmd cmd, int flag)
{
	/*if (flag == 1)
	{
		if (path_mode(cmd) == 1)
			ft_putstr_fd("minishell: error: path is a builtin", 2);
	}*/
	if (flag == 0)
		cmd_mode(cmd);
}
