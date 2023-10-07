/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:08:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/10/07 13:24:13 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*falta argumentos para linkar isto com o resto do projeto
  mas fora isso esta pronto*/

void	find_builtins(int fd)
{
	char **cmd;

	if (!ft_strncmp(cmd[0], "pwd", 3))
		func_pwd(fd);
	else if (!ft_strncmp(cmd[0], "echo", 4))
		func_echo(fd);
	else if (!ft_strncmp(cmd[0], "cd", 2))
		func_cd(int fd);
	else if (!ft_strncmp(cmd[0], "env", 3))
		func_env(int fd);
	else if (!ft_strncmp(cmd[0], "export", 6))
		func_export(int fd);
	else if (!ft_strncmp(cmd[0], "exit", 4))
		func_exit(int fd);
	else if (!ft_strncmp(cmd[0], "unset", 5))
		func_unset(int fd);
}