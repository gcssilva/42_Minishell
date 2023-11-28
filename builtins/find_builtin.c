/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:08:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/28 12:07:43 by gmorais-         ###   ########.fr       */
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

/*static int	path_mode(char *cmd)
{
	if (!ft_strnstr(cmd, "pwd", 3))
		return (1);
	else if (!ft_strnstr(cmd, "echo", 4))
		return (1);
	else if (!ft_strnstr(cmd, "cd", 2))
		return (1);
	else if (!ft_strnstr(cmd, "exit", 4))
		return (1);
	else if (!ft_strnstr(cmd, "export", 6))
		return (1);
	else if (!ft_strnstr(cmd, "env", 3))
		return (1);
	else if (!ft_strnstr(cmd, "unset", 5))
		return (1);
	else
		func_exec(cmd);
	return (0);
}*/

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
