/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:08:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/30 15:57:19 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta argumentos para linkar isto com o resto do projeto
  mas fora isso esta pronto
builtins finalizado porem sem testes
*/

static void	cmd_mode(char **cmd, char ***env)
{
	if (!ft_strncmp(cmd[0], "pwd", 3))
		func_pwd();
	else if (!ft_strncmp(cmd[0], "echo", 4))
		func_echo(cmd);
	else if (!ft_strncmp(cmd[0], "cd", 2))
		func_cd(cmd, env);
	else if (!ft_strncmp(cmd[0], "exit", 4))
		func_exit(cmd, env);
	else if (!ft_strncmp(cmd[0], "export", 6))
		func_export(cmd, env);
	else if (!ft_strncmp(cmd[0], "env", 3))
		func_env(*env);
	else if (!ft_strncmp(cmd[0], "unset", 5))
		func_unset(cmd, *env);
	else
		func_exec(cmd[0], env);
}

static int	path_mode(char **cmd, char ***env)
{
	if (!ft_strncmp(cmd[0], "pwd", 3))
		return (1);
	else if (!ft_strncmp(cmd[0], "echo", 4))
		return (1);
	else if (!ft_strncmp(cmd[0], "cd", 2))
		return (1);
	else if (!ft_strncmp(cmd[0], "exit", 4))
		return (1);
	else if (!ft_strncmp(cmd[0], "export", 6))
		return (1);
	else if (!ft_strncmp(cmd[0], "env", 3))
		return (1);
	else if (!ft_strncmp(cmd[0], "unset", 5))
		return (1);
	else
		func_exec(cmd[0], env);
	return (0);
}

void	find_builtins(char **cmd, char ***env, int flag)
{
	if (flag == 1)
	{
		if (path_mode(cmd, env) == 1)
			ft_putstr_fd("minishell: error: path is a builtin", 2);
	}
	else if (flag == 0)
		cmd_mode(cmd, env);
}
